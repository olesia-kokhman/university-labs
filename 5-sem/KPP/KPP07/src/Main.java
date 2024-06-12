import org.crossplatform.Bank;
import org.crossplatform.Client;

import java.util.ArrayList;
import java.util.List;

public class Main {
    public static void main(String[] args) {

        int numberOfThreads = 3;
        int initialBalance = 1000;

        Bank bank = new Bank(initialBalance);

        List<Client> clients = new ArrayList<>();
        List<Thread> threads = new ArrayList<>();

        for (int i = 0; i < numberOfThreads; i++) {
            Client client = new Client(bank, "Client " + (i + 1));
            Thread thread = new Thread(client);

            int initialPriority = thread.getPriority();
            System.out.println("Initial priority of " + thread.getName() + ": " + initialPriority);

            thread.setPriority((int) (Math.random() * Thread.MAX_PRIORITY));
            System.out.println("New priority of " + thread.getName() + ": " + thread.getPriority());

            clients.add(client);
            threads.add(thread);

            thread.start();
            client.getInfo();
        }

        try {
            Thread.sleep(3000);

            int randomClientIndex = (int) (Math.random() * numberOfThreads);
            clients.get(randomClientIndex).suspendClient();
            System.out.println(clients.get(randomClientIndex).getClientName() + " suspended...");

            Thread.sleep(2000);
            clients.get(randomClientIndex).resumeClient();
            System.out.println(clients.get(randomClientIndex).getClientName() + " resumed...");
        } catch (InterruptedException e) {
            throw new RuntimeException(e);
        }

    }


}