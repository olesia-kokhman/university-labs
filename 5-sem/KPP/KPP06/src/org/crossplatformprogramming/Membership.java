package org.crossplatformprogramming;

import java.time.LocalDate;
import java.util.Comparator;
import java.util.List;

public class Membership {

    private String fullName;
    private String email;

    private List<Book> books;
    private LocalDate issueDate;
    private LocalDate returnDate;
    private LocalDate realReturnDate;

    public Membership(String fullName, String email, List<Book> books) {
        this.fullName = fullName;
        this.email = email;
        this.books = books;
        this.realReturnDate = null;
    }

    @Override
    public String toString() {
        return "\nMembership{" +
                "fullName='" + fullName + '\'' +
                ", email='" + email + '\'' +
                ", books=" + books +
                '}';
    }

    public List<Book> getBooks() {
        return this.books;
    }

    public String getEmail() {
        return this.email;
    }

    public LocalDate getRealReturnDate() {
        return this.realReturnDate;
    }

    public void setIssueDate(LocalDate issueDate) {
        this.issueDate = issueDate;
    }

    public void setReturnDate(LocalDate returnDate) {
        this.returnDate = returnDate;
    }

    public void setRealReturnDate(LocalDate realReturnDate) {
        this.realReturnDate = realReturnDate;
    }

    public static class BookListLengthComparator implements Comparator<Membership> {

        @Override
        public int compare(Membership membership1, Membership membership2) {
            return Integer.compare(membership1.getBooks().size(), membership2.getBooks().size());
        }
    }
}
