import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;


class Book implements Comparable<Book> {
    private int id;
    private String title;
    private String author;
    private String publisher;

    // Constructor, getters and setters

    public Book(int id, String title, String author, String publisher) {
        this.id = id;
        this.title = title;
        this.author = author;
        this.publisher = publisher;
    }

    public int getId() {
        return id;
    }

    public String getTitle() {
        return title;
    }

    public String getAuthor() {
        return author;
    }

    public String getPublisher() {
        return publisher;
    }

    @Override
    public int compareTo(Book other) {
        return this.id - other.id;
    }
}

class TitleComparator implements Comparator<Book> {
    @Override
    public int compare(Book b1, Book b2) {
        return b1.getTitle().compareTo(b2.getTitle());
    }
}

class AuthorComparator implements Comparator<Book> {
    @Override
    public int compare(Book b1, Book b2) {
        return b1.getAuthor().compareTo(b2.getAuthor());
    }
}

class PublisherComparator implements Comparator<Book> {
    @Override
    public int compare(Book b1, Book b2) {
        return b1.getPublisher().compareTo(b2.getPublisher());
    }
}

public class Prac6_3 {
    public static void main(String[] args) {
        List<Book> books = Arrays.asList(
            new Book(2, "Title2", "Author2", "Publisher2"),
            new Book(1, "Title1", "Author1", "Publisher1"),
            new Book(3, "Title3", "Author3", "Publisher3")
        );

        Collections.sort(books);
        System.out.println("Books sorted by ID:");
        for (Book book : books) {
            System.out.println(book.getId() + " " + book.getTitle());
        }

        Collections.sort(books, new TitleComparator());
        System.out.println("\nBooks sorted by title:");
        for (Book book : books) {
            System.out.println(book.getId() + " " + book.getTitle());
        }

        Collections.sort(books, new AuthorComparator());
        System.out.println("\nBooks sorted by author:");
        for (Book book : books) {
            System.out.println(book.getId() + " " + book.getAuthor());
        }

        Collections.sort(books, new PublisherComparator());
        System.out.println("\nBooks sorted by publisher:");
        for (Book book : books) {
            System.out.println(book.getId() + " " + book.getPublisher());
        }
    }
}