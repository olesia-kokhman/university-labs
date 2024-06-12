package org.crossplatformprogramming;

import java.time.LocalDate;
import java.util.Scanner;

public class LibraryMenu {
    Library library;

    public LibraryMenu(Library library) {
        this.library = library;
    }

    public void run() {
        System.out.println("Welcome to the library!");
        System.out.println("1 - sort books by publication date\n" +
                "2 - get emails of multiple borrowed books\n" +
                "3 - get the number of people who borrowed the appropriate author\n" +
                "4 - find a membership who borrowed max number of books\n" +
                "5 - send messages to all the memberships\n" +
                "6 - create a list of people who are late with return date");
        int option = scanOption();
        while(option != 0){
            switch(option) {
                case 1:
                    System.out.println(library.sortBooksByPublicationDate().toString());
                    break;
                case 2:
                    System.out.println(library.getEmailsMultipleBooksBorrowed().toString());
                    break;
                case 3:
                    Scanner scanner = new Scanner(System.in);
                    System.out.println(library.countMembershipsThisAuthorBooksBorrowed(scanner.nextLine()));
                    break;
                case 4:
                    System.out.println(library.findMembershipBorrowedMaxBooks().toString());
                    break;
                case 5:
                    NewsletterSender.sendOneBookMessage(library.getEmailsOneBookBorrowed());
                    NewsletterSender.sendMultipleBooksMessage(library.getEmailsMultipleBooksBorrowed());
                    break;
                case 6:
                    System.out.println(library.getReturnDateLessThan(LocalDate.now()).toString());
                    break;
            }
            option = scanOption();
        }

    }

    public int scanOption() {
        System.out.println("Please choose the option you want to run:");
        Scanner scanner = new Scanner(System.in);
        int option = scanner.nextInt();
        return option;
    }


}
