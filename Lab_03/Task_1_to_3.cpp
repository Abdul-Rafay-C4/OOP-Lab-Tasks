#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

struct student
{
    int id;
    string name;
    float grade;
    student(int i, string n, float g) : id(i), name(n), grade(g) {}
};

class student_manager
{
private:
    vector<student*> records;
    map<int, student*> id_student; // Map to efficiently find students by ID
public:
    void add_student(int id, string name, float grade)
    {
        student *new_student = new student(id, name, grade);
        records.push_back(new_student);
        id_student[id] = new_student; // Update the map
    }
    
    void update_grade(int id, float new_grade)
    {
        if(id_student.find(id) != id_student.end())
        {
            id_student[id] -> grade = new_grade;
            cout << "\nGrade updated successfully for student ID: " << id << endl;
        }
        else
        {
            cout << "\nStudent ID not found." << endl;
        }
    }
    
    void display_records()
    {
        for(student *student : records)
        {
            cout << "\nID: \t" << student -> id << ",\nName: \t" << student -> name << ",\nGrade: \t" << student -> grade << endl;
        }
    }
    
    ~student_manager()
    {
        for(student *student : records)
        {
            delete student;
        }
    }
};

class contact_manager
{
private:
    map<string, string> contacts; // Map to store contacts (name -> details)
public:
    void add_contact(string name, string details)
    {
        contacts[name] = details;
        cout << "\tContact added successfully for " << name << endl;
    }
    
    void search_contact(string name)
    {
        if(contacts.find(name) != contacts.end())
        {
            cout << "\tContact details for " << name << ": " << contacts[name] << endl;
        }
        else
        {
            cout << "\tContact not found." << endl;
        }
    }
};

int main()
{
    // Task 1: Vector Manipulation
    vector<float> grades;
    grades.push_back(85.5);
    grades.push_back(90.0);
    grades.push_back(78.5);
    
    cout << "Grades:";
    for(float grade : grades)
    {
        cout << " " << grade;
    }
    cout << endl;

    // Task 2: Map Usage
    contact_manager cm;
    cm.add_contact("Jibran", "1234567890");
    cm.add_contact("Jibran lames", "9876543210");
    cm.search_contact("Jibran");
    cm.search_contact("Raza");

    // Task 3: student Record Management System
    student_manager sm;
    sm.add_student(1, "Jibran", 92.5);
    sm.add_student(2, "Jibran lames", 88.0);
    sm.display_records();
    sm.update_grade(1, 95.0);
    cout << "After grade update:" << endl;
    sm.display_records();

    return 0;
}
