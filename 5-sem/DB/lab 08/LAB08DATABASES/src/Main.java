import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.time.LocalDate;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Connection connection = null;
        try {
            connection = DriverManager.getConnection("jdbc:postgresql://localhost:5432/sales",
                    "postgres",
                    "somepassword");
            connection.setAutoCommit(false);
            DBExecutor executor = new DBExecutor(connection);

            System.out.println("-----------------------------------------------------------------------");
            executor.insertWithExistingId(1, true);
            connection.setAutoCommit(true);

            System.out.println("-----------------------------------------------------------------------");
            System.out.println("Enter id to execute select query:");
            Scanner scanner = new Scanner(System.in);
            int scannedId = scanner.nextInt();
            executor.selectWithParameter(scannedId);

            System.out.println("-----------------------------------------------------------------------");
            int id = 160;
            double amount = 550.55;
            String status = "pending";
            LocalDate createdAt = LocalDate.now();
            String billingType = "Payoneer";
            LocalDate purchasedAt = LocalDate.now();
            int projectId = 1;
            executor.insertPaymentWithParameters(id, amount, status, createdAt, billingType, purchasedAt, projectId);

            System.out.println("-----------------------------------------------------------------------");
            executor.callProcedure();

            connection.close();
        } catch (SQLException exception) {
            throw new RuntimeException();
        }
    }
}