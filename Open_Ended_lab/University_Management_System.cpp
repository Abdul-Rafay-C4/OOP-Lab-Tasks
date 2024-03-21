#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

class Course; // forward diclaration 

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
        void dropCourse(Course* course);
        void viewCourses();
        friend class Course;
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
        friend class Course;
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
                cout << student -> studentID << " - " << student -> name << endl;
            }
        }
        string getCourseCode() const { return courseCode; }

        friend class Student;
        friend class Teacher; 
};
void loadData(vector<Student*>& students, vector<Teacher*>& teachers, vector<Course*>& courses);
void saveData(const vector<Student*>& students, const vector<Teacher*>& teachers, const vector<Course*>& courses);
int main()
{

}

//Studnet Class Methods
void Student::enrollCourse(Course*course)
{
    if(course -> studentsEnrolled.size() < course -> maxCapacity)
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

void Student::dropCourse(Course* course)
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

void Student::viewCourses()
{
    cout << "Enrolled Courses:" << endl;
    for(auto course : coursesEnrolled)
    {
        cout << course -> courseName << endl;
    }
}

//Teacher Class Methods
void Teacher::assignCourse(Course* course)
{
    coursesTaught.push_back(course);
    course -> teacher = this;
    cout << "Assigned " << course -> courseName << " to " << name << "." << endl;
}

void Teacher::removeCourse(Course* course)
{
    auto it = find(coursesTaught.begin(), coursesTaught.end(), course);
    if(it != coursesTaught.end())
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

void Teacher::viewCourses()
{
    cout << "Courses Taught:" << endl;
    for(auto course : coursesTaught)
    {
        cout << course -> courseName << endl;
    }
}

void loadData(vector<Student*>& students, vector<Teacher*>& teachers, vector<Course*>& courses)
{
    ifstream file("data.txt");
    if(file.is_open())
    {
        string line;
        while(getline(file, line))
        {
            string type;
            istringstream iss(line);
            iss >> type;
            if(type == "Student:")
            {
                string studentID, name, email;
                char delim;
                iss >> studentID >> delim >> name >> delim >> email;
                students.push_back(new Student(studentID, name, email));
            }
            else if(type == "Teacher:")
            {
                string teacherID, name, email;
                char delim;
                iss >> teacherID >> delim >> name >> delim >> email;
                teachers.push_back(new Teacher(teacherID, name, email));
            }else if(type == "Course:")
            {
                string courseCode, courseName;
                int maxCapacity;
                char delim;
                iss >> courseCode >> delim >> courseName >> delim >> maxCapacity;
                courses.push_back(new Course(courseCode, courseName, maxCapacity));
            }
        }
        file.close();
        cout << "Data loaded successfully." << endl;
    }
    else
    {
        cout << "Unable to open file." << endl;
    }
}
void saveData(const vector<Student*>& students, const vector<Teacher*>& teachers, const vector<Course*>& courses)
{
    ofstream file("data.txt");
    if(file.is_open())
    {
        for(auto student : students)
        {
            file << "Student: " << student -> getStudentID() << "," << student -> name << "," << student -> email << endl;
        }
        for(auto teacher : teachers)
        {
            file << "Teacher: " << teacher -> teacherID << "," << teacher -> name << "," << teacher -> email << endl;
        }
        for(auto course : courses)
        {
            file << "Course: " << course -> courseCode << "," << course -> courseName << "," << course -> maxCapacity << endl;
        }
        file.close();
        cout << "Data saved successfully." << endl;
    }
    else
    {
        cout << "Unable to open file." << endl;
    } 
}