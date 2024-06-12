import java.sql.*;
import java.time.LocalDate;

public class DBExecutor {

    private Connection connection;

    public DBExecutor(Connection connection) {
        this.connection = connection;
    }

    public void insertWithExistingId(int id, boolean doRecursion) {
        String query = "INSERT INTO public.\"Developers\" " +
                "(id, name, bonuses)" +
                "VALUES (?, ?, ?)";

        int developerId = id;
        String nameDev = "Super cool sales person";
        int bonuses = 500;

        try {
            PreparedStatement preparedStatement = connection.prepareStatement(query);
            preparedStatement.setInt(1, developerId);
            preparedStatement.setString(2, nameDev);
            preparedStatement.setInt(3, bonuses);

            preparedStatement.executeUpdate();
            connection.commit();

            System.out.println("commit was done");
            preparedStatement.close();
        } catch(SQLException exception) {
            try {
                System.out.println(exception.getMessage());
                connection.rollback();
                System.out.println("rollback was successful");
                if(!doRecursion) {
                    updateWhenExistingId(developerId, nameDev, bonuses);

                    return;
                }
                insertWithExistingId(157, false);
            } catch (SQLException e) {
                throw new RuntimeException(e);
            }
        }
    }

    public void updateWhenExistingId(int id, String name, int bonuses) {
        String updateQuery = ("UPDATE public.\"Developers\" SET name = ?, bonuses = ? WHERE id = ?");

        try {
            PreparedStatement preparedStatementUpdate = connection.prepareStatement(updateQuery);
            preparedStatementUpdate.setString(1, name);
            preparedStatementUpdate.setInt(2, bonuses);
            preparedStatementUpdate.setInt(3, id);

            int rowsAffected = preparedStatementUpdate.executeUpdate();

            if (rowsAffected > 0) {
                System.out.println("Update successful");
            }
            preparedStatementUpdate.close();
        } catch (SQLException exception) {
            System.out.println(exception.getMessage());
        }
    }

    public void selectWithParameter(int scannedId) {
        String query = "SELECT * FROM public.\"Sales\" WHERE id >= ?";
        try {
            PreparedStatement preparedStatement = connection.prepareStatement(query);
            preparedStatement.setInt(1, scannedId);
            ResultSet resultSet = preparedStatement.executeQuery();

            while (resultSet.next()) {
                int id = resultSet.getInt("id");
                String name = resultSet.getString("name");
                int projectNumber = resultSet.getInt("project_number");
                System.out.println(id + " " + name + " " + projectNumber);
            }

            preparedStatement.close();
            resultSet.close();

        } catch(SQLException exception) {
            System.out.println(exception.getMessage());
        }
    }

    public void insertPaymentWithParameters(int id, double amount, String status, LocalDate createdAt,
                                            String billingType, LocalDate purchasedAt, int projectId) {
        String query = "INSERT INTO public.\"Payments\" " +
                    "(id, amount, status, created_at, billing_type, purchased_at, project_id)" +
                    "VALUES (?, ?, ?, ?, ?, ?, ?)";

            try {
                PreparedStatement preparedStatement = connection.prepareStatement(query);
                preparedStatement.setInt(1, id);
                preparedStatement.setDouble(2, amount);
                preparedStatement.setString(3, status);
                preparedStatement.setDate(4, Date.valueOf(createdAt));
                preparedStatement.setString(5, billingType);
                preparedStatement.setDate(6, Date.valueOf(purchasedAt));
                preparedStatement.setInt(7, projectId);

                int rowsAffected = preparedStatement.executeUpdate();

                if (rowsAffected > 0) {
                    System.out.println("Payment added successfully.");
                }
                preparedStatement.close();
            } catch (SQLException exception) {
                System.out.println(exception.getMessage());
            }
    }

    public void callProcedure() {
        String query = "CALL update_sales_project_number(?)";

        try {
            CallableStatement callableStatement = connection.prepareCall(query);
            int saleId = 1;
            callableStatement.setInt(1, saleId);
            callableStatement.execute();

            System.out.println("Procedure was called successfully");
            callableStatement.close();
        } catch (SQLException exception) {
            System.out.println(exception.getMessage());
        }

    }

}
