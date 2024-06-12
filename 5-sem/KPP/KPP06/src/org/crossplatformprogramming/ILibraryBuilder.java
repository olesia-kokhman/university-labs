package org.crossplatformprogramming;

import java.util.List;

public interface ILibraryBuilder {
    List<Book> buildBookList();
    List<Membership> buildMembershipList(List<Book> books);
}
