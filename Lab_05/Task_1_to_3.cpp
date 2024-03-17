#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Book
{
private:
    string title;
    string author;
    int publicationYear;

public:
    // Constructor
    Book(const string& _title, const string& _author, int _publicationYear)
        : title(_title), author(_author), publicationYear(_publicationYear) {}

    // Getters
    string getTitle() const
    {
        return title;
    }
    string getAuthor() const
    {
        return author;
    }
    int getPublicationYear() const
    {
        return publicationYear;
    }
};

class BookManager
{
private:
    vector<Book> books;

public:
    // Function to add a book
    void addBook(const Book& book)
    {
        books.push_back(book);
        cout << "Book added successfully." << endl;
    }

    // Function to remove a book
    void removeBook(const string& title)
    {
        // Find the book with the given title
        auto it = std::find_if(books.begin(), books.end(), [&title](const Book& book)
        {
            return book.getTitle() == title;
        });
        // If book found, remove it
        if(it != books.end())
        {
            books.erase(it);
            cout << "Book removed successfully." << endl;
        }
        else
        {
            // If book not found, print error message
            cout << "Book with title '" << title << "' not found." << endl;
        }
    }

    // Function to list all books
    void listBooks() const
    {
        cout << "List of Books:" << endl;
        // Iterate through books and print details of each book
        for(const auto& book : books)
        {
            cout << "Title: " << book.getTitle() << ", Author: " << book.getAuthor() << ", Publication Year: " << book.getPublicationYear() << endl;
        }
    }
};

int main()
{
    // Usage example
    BookManager manager;
    manager.addBook(Book("Title1", "Author1", 2000));
    manager.addBook(Book("Title2", "Author2", 2010));
    manager.addBook(Book("Title3", "Author3", 2020));

    // List all books
    manager.listBooks();

    // Remove a book and handle errors
    manager.removeBook("Title2");
    manager.removeBook("Title4");

    // List books after removal
    manager.listBooks();

    return 0;
}
