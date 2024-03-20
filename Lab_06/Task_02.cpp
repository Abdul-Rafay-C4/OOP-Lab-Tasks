#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Book 
{
private:
  string title;
  string author;
  int year;

public:
  Book(const string& _title, const string& _author, int _year)
      : title(_title), author(_author), year(_year) {}

  // Getters (combined into a single function)
  const string& get_info() const
  {
    static string info; // Static variable to store info string
    info = "Title: " + title + ", Author: " + author + ", Year: " + to_string(year);
    return info;
  }

  void display() const 
  {
    cout << get_info() << endl;
  }

  // Overloading operator== to compare Book objects based on their titles
  bool operator==(const Book& other) const
  {
    return this->title == other.title;
  }
};

class Library
{
private:
  vector<Book> books;

public:
  // Method to add a book to the library
  void add_book(const Book& book)
  {
    books.push_back(book);
    cout << "Book added successfully!\n";
  }

  // Method to remove a book from the library by title (using std::find)
  bool remove_book(const string& title)
  {
    auto it = find(books.begin(), books.end(), Book(title, "", 0)); // Search by title only
    if(it != books.end())
    {
      books.erase(it);
      cout << "Book removed successfully!\n";
      return true;
    }
    else
    {
      cout << "Book not found!\n";
      return false;
    }
  }

  // Method to list all books in the library
  void list_books() const
  {
    if(books.empty())
    {
      cout << "Library is empty.\n";
      return;
    }
    cout << "Books in the library:\n";
    for(const auto& book : books)
    {
      book.display();
    }
  }
};

int main() 
{
  Library library;
  while (true) {
    cout << "\nWelcome to the Book Management System\n";
    cout << "1. Add a book\n";
    cout << "2. Remove a book\n";
    cout << "3. List all books\n";
    cout << "4. Exit\n";
    cout << "Enter your choice: ";

    int choice;
    cin >> choice;
    cin.ignore(); // Clear the input buffer

    switch (choice) {
      case 1: {
        string title, author;
        int year;
        cout << "Enter title: ";
        getline(cin, title);
        cout << "Enter author: ";
        getline(cin, author);
        cout << "Enter year of publication: ";
        cin >> year;
        cin.ignore(); // Clear the input buffer
        Book newBook(title, author, year);
        library.add_book(newBook);
        break;
      }
      case 2: {
        string title;
        cout << "Enter title of the book to remove: ";
        getline(cin, title);
        library.remove_book(title);
        break;
      }
      case 3:
        library.list_books();
        break;
      case 4:
        cout << "Exiting...\n";
        return 0;
      default:
        cout << "Invalid choice. Please enter a number from 1 to 4.\n";
    }
  }

  return 0;
}
