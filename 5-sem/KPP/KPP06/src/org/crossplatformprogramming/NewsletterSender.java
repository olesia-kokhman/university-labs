package org.crossplatformprogramming;

import java.util.List;

public class NewsletterSender {

    public static void sendOneBookMessage(List<String> emails) {
        emails.forEach(email -> System.out.println(email + " - here are new books for you to read! let's go and take them"));
    }

    public static void sendMultipleBooksMessage(List<String> emails) {
        emails.forEach(email -> System.out.println(email + " - Wish interesting reading! Don't forget to get these books back soon"));
    }
}
