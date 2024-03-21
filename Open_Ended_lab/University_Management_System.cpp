#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

class Student 
{    
    private:
    string studentID;
    string name;
    string email;
    vector<Course*> coursesEnrolled;

public:
    Student(string studentID, string name, string email): studentID(studentID), name(name), email(email) {}

    void enrollCourse(Course*course);
    void dropCourse(Course*course);
    void viewCourses();
    string getStudentID() const {return studentID;}

void enrollCourse(Course*course)
{
    if(course->studentsEnrolled.size() < course-> maxCapacity)
    {
        coursesEnrolled.push_back(course);
        course -> addStudent(this);
        cout << "Enrolled in " << course -> courseName << "." << endl;
    }
    else
    {
        cout << "Cannot enroll in " << course -> courseName << ". Course is full." << endl;
    }
}

void dropCourse(Course* course)
{
    auto it = find(coursesEnrolled.begin(), coursesEnrolled.end(), course);
    if(it != coursesEnrolled.end())
    {
        coursesEnrolled.erase(it);
        course -> removeStudent(this);
        cout << "Dropped " << course -> courseName << "." << endl;
    }
    else
    {
        cout << "Not enrolled in " << course -> courseName << "." << endl;
    }
}

void viewCourses()
    {
    cout << "Enrolled Courses:" << endl;
    for(auto course : coursesEnrolled)
    {
        cout << course -> courseName << endl;
    }
}
};

class Teacher
{
    private:
    string teacherID;
    string name;
    string email;
    vector<Course*> coursesTaught;

public:
    Teacher(string teacherID, string name, string email) : teacherID(teacherID), name(name), email(email) {}

    void assignCourse(Course* course);
    void removeCourse(Course* course);
    void viewCourses();

    void assignCourse(Course* course)
{
    coursesTaught.push_back(course);
    course -> teacher = this;
    cout << "Assigned " << course -> courseName << " to " << name << "." << endl;
}

void removeCourse(Course* course)
{
    auto it = find(coursesTaught.begin(), coursesTaught.end(), course);
    if (it != coursesTaught.end())
    {
        coursesTaught.erase(it);
        course -> teacher = nullptr;
        cout << "Removed " << course -> courseName << " from " << name << "." << endl;
    }
    else
    {
        cout << "Not teaching " << course -> courseName << "." << endl;
    }
}

void viewCourses()
    {
    cout << "Courses Taught:" << endl;
    for (auto course : coursesTaught)
    {
        cout << course -> courseName << endl;
    }
}
};

class Course
{
    private:
    string courseCode;
    string courseName;
    Teacher* teacher;
    vector<Student*> studentsEnrolled;
    int maxCapacity;

public:
    Course(string courseCode, string courseName, int maxCapacity) : courseCode(courseCode), courseName(courseName), teacher(nullptr), maxCapacity(maxCapacity) {}

    void addStudent(Student* student)
    {
        studentsEnrolled.push_back(student);
    }

    void removeStudent(Student* student)
    {
        auto it = find(studentsEnrolled.begin(), studentsEnrolled.end(), student);
        if(it != studentsEnrolled.end())
        {
            studentsEnrolled.erase(it);
        }
    }

    void viewStudents()
    {
        cout << "Students Enrolled in " << courseName << ":" << endl;
        for(auto student : studentsEnrolled)
        {
            cout << student->getStudentID() << " - " << student->name << endl;
        }
    }
    string getCourseCode() const { return courseCode; }
};

int main()
{

}


