package org.crossplatformprogramming;

import java.time.LocalDate;
import java.util.Comparator;

public class Book {

    private String author;
    private String title;
    private LocalDate publicationDate;

    private int code;

    public Book(String author, String title, LocalDate publicationDate, int code) {
        this.author = author;
        this.title = title;
        this.publicationDate = publicationDate;
        this.code = code;
    }

    @Override
    public String toString() {
        return "\nBook{" +
                "author='" + author + '\'' +
                ", title='" + title + '\'' +
                ", publicationDate=" + publicationDate +
                ", code=" + code +
                '}';
    }

    public LocalDate getPublicationDate() {
        return this.publicationDate;
    }

    public String getAuthor() {
        return this.author;
    }

    public int getCode() {
        return this.code;
    }

    public static class PublicationDateComparator implements Comparator<Book> {
        @Override
        public int compare(Book book1, Book book2) {
            return book1.getPublicationDate().compareTo(book2.getPublicationDate());
        }
    }
}
