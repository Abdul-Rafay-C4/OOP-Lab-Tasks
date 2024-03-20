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
  const string& getInfo() const
  {
    static string info; // Static variable to store info string
    info = "Title: " + title + ", Author: " + author + ", Year: " + to_string(year);
    return info;
  }

  void display() const 
  {
    cout << getInfo() << endl;
  }
};

class Library {
private:
  vector<Book> books;

public:
  // Method to add a book to the library
  void addBook(const Book& book) {
    books.push_back(book);
    cout << "Book added successfully!\n";
  }

  // Method to remove a book from the library by title (using std::find)
  bool removeBook(const string& title) {
    auto it = find(books.begin(), books.end(), Book(title, "", 0)); // Search by title only
    if (it != books.end()) {
      books.erase(it);
      cout << "Book removed successfully!\n";
      return true;
    } else {
      cout << "Book not found!\n";
      return false;
    }
  }

  // Method to list all books in the library
  void listBooks() const {
    if (books.empty()) {
      cout << "Library is empty.\n";
      return;
    }
    cout << "Books in the library:\n";
    for (const auto& book : books) {
      book.display();
    }
  }
};


int main() 
{

}
