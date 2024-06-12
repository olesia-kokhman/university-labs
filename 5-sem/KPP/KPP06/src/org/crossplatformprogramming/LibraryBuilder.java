package org.crossplatformprogramming;

import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.util.ArrayList;
import java.util.List;

public class LibraryBuilder implements ILibraryBuilder {
    private Library library;
    private static int counter = 1;

    public LibraryBuilder() {
        List<Book> books = buildBookList();
        List<Membership> memberships = buildMembershipList(books);
        library = new Library(books, memberships);
    }

    public List<Book> buildBookList() {
        CustomFileReader<Book> bookCustomFileReader = new CustomFileReader<>(
                "C:\\university\\5-sem\\KPP\\KPP06\\src\\books.txt");
        List<Book> books = bookCustomFileReader.getObjects(line -> {
            String[] string = line.split(", ");
            String author = string[0];
            String title = string[1];
            LocalDate publicationDate = LocalDate.parse(string[2], DateTimeFormatter.ofPattern("yyyy-MM-dd"));
            int code = Integer.parseInt(string[3]);
            return new Book(author, title, publicationDate, code);
        });

        return books;
    }

    public List<Membership> buildMembershipList(List<Book> books) {
        CustomFileReader<Membership> membershipCustomFileReader = new CustomFileReader<>(
                "C:\\university\\5-sem\\KPP\\KPP06\\src\\memberships.txt");
        List<Membership> memberships = membershipCustomFileReader.getObjects(line -> {
            String[] parts = line.split(" - ");
            String[] userInfo = parts[0].split(", ");
            String fullName = userInfo[0];
            String email = userInfo[1];

            String[] bookCodesArray = parts[1].split(", ");

            List<Integer> bookCodesList = new ArrayList<>();
            for (String s : bookCodesArray) {
                bookCodesList.add(Integer.parseInt(s));
            }

            List<Book> membershipBooks = new ArrayList<>();
            for(Integer code: bookCodesList) {
                books.forEach(book -> {
                    if ( book.getCode() == code) {
                        membershipBooks.add(book);
                    }
                });

            }

            Membership membership = new Membership(fullName, email, membershipBooks);

            Admin.noteIssueDate(membership);
            if(counter % 2 == 0) {
                Admin.noteRealReturnDate(membership);
            }

            return membership;

        });

        return memberships;

    }

    public Library getLibrary() {
        return this.library;
    }
}
