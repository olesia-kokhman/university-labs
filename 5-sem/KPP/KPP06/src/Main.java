import org.crossplatformprogramming.*;

public class Main {
    public static void main(String[] args) {
        LibraryBuilder libraryBuilder = new LibraryBuilder();
        Library library = libraryBuilder.getLibrary();

        LibraryMenu menu = new LibraryMenu(library);
        menu.run();
    }
}