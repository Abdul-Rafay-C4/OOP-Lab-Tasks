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



int main() 
{

}
