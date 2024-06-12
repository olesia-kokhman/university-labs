package org.crossplatformprogramming;

import java.time.LocalDate;
import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;

public class Library {

    private List<Book> books;
    private List<Membership> memberships;

    public Library(List<Book> books, List<Membership> memberships) {
        this.books = books;
        this.memberships = memberships;
    }

    public List<Book> sortBooksByPublicationDate() {
        return books.stream().sorted(new Book.PublicationDateComparator()).toList();
    }

    public List<String> getEmailsMultipleBooksBorrowed() {
        List<String> emailsForNewsletter = new ArrayList<>();
        memberships.stream().filter(membership -> membership.getBooks().size() >= 2)
                .forEach(membership -> emailsForNewsletter.add(membership.getEmail()));
        return emailsForNewsletter;
    }

    public List<String> getEmailsOneBookBorrowed() {
        return memberships.stream()
                .filter(membership -> membership.getBooks().size() < 2)
                .map(Membership::getEmail)
                .collect(Collectors.toList());
    }


    public int countMembershipsThisAuthorBooksBorrowed(String author) {
        return (int) memberships.stream().filter( membership -> membership.getBooks()
                .stream().anyMatch(book -> book.getAuthor().equals(author))
            ).count();
    }

    public Membership findMembershipBorrowedMaxBooks() {
        return memberships.stream().max(new Membership.BookListLengthComparator()).orElse(null);
    }

    public List<Membership> getReturnDateLessThan(LocalDate runningDate) {
        return memberships.stream().filter(membership -> membership.getRealReturnDate() == null)
                .collect(Collectors.toList());
    }

}
