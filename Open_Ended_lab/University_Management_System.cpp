#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <cctype>
#include <locale>

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
        string get(string input)
        {
            if(input == "studentID")
            {
                return studentID;
            }
            else if(input == "name")
            {
                return name;
            }
            else if(input == "email")
            {
                return email;
            }
            return 0;
        }
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
        string get(string input)
        {
            if(input == "teacherID")
            {
                return teacherID;
            }
            else if(input == "name")
            {
                return name;
            }
            else if(input == "email")
            {
                return email;
            }
            return 0;
        }
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
        string get(string input)
        {
            if(input == "courseCode")
            {
                return courseCode;
            }
            else if(input == "courseName")
            {
                return courseName;
            }
            else if(input == "maxCapacity")
            {
                return to_string(maxCapacity);
            }
            return 0;
        }

        friend class Student;
        friend class Teacher; 
};
void loadData(vector<Student*>& students, vector<Teacher*>& teachers, vector<Course*>& courses);
void saveData(const vector<Student*>& students, const vector<Teacher*>& teachers, const vector<Course*>& courses);
string trim(const string& str);
void registerStudent(vector<Student*>& students);
void registerTeacher(vector<Teacher*>& teachers);
void registerCourse(vector<Course*>& courses);
int main()
{
    vector<Student*> students;
    vector<Teacher*> teachers;
    vector<Course*> courses;

    // Load data from file
    loadData(students, teachers, courses);

    int choice;
    while(true)
    {
        cout << "\nUniversity Management System" << endl;
        cout << "1. Proceed as Student" << endl;
        cout << "2. Proceed as Teacher" << endl;
        cout << "3. Proceed as Course" << endl;
        cout << "4. Register Student" << endl;
        cout << "5. Register Teacher" << endl;
        cout << "6. Register Course" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Clear the input buffer

        switch(choice)
        {
            case 1:
            {
                // Proceed as Student
                cout << "\nStudent Functionality Menu:" << endl;
                cout << "1. Enroll in Course" << endl;
                cout << "2. Drop Course" << endl;
                cout << "3. View Enrolled Courses" << endl;
                cout << "Enter your choice: ";
                int studentChoice;
                cin >> studentChoice;
                cin.ignore(); // Clear the input buffer

                string studentID, courseCode;
                switch(studentChoice)
                {
                    case 1:
                    {
                        cout << "Enter student ID: ";
                        getline(cin, studentID);
                        cout << "Enter course code: ";
                        getline(cin, courseCode);

                        // Trim leading and trailing whitespace
                        studentID = trim(studentID);
                        courseCode = trim(courseCode);

                        cout << "Entered student ID: " << studentID << endl;
                        cout << "Entered course code: " << courseCode << endl;

                        Student* student = nullptr;
                        Course* course = nullptr;

                        for(auto s : students)
                        {
                            if(s -> get("studentID") == studentID)
                            {
                                student = s;
                                break;
                            }
                        }
                        for(auto c : courses)
                        {
                            if(c -> get("courseCode") == courseCode)
                            {
                                course = c;
                                break;
                            }
                        }
                        if(student && course)
                        {
                            student -> enrollCourse(course);
                        }
                        else
                        {
                            cout << "Student or course not found." << endl;
                        }
                        break;
                    }
                    case 2:
                    {
                        cout << "Enter student ID: ";
                        getline(cin, studentID);
                        cout << "Enter course code: ";
                        getline(cin, courseCode);
                        Student* student = nullptr;
                        Course* course = nullptr;
                        for(auto s : students)
                        {
                            if(s -> get("studentID") == studentID)
                            {
                                student = s;
                                break;
                            }
                        }
                        for(auto c : courses)
                        {
                            if(c -> get("courseCode") == courseCode)
                            {
                                course = c;
                                break;
                            }
                        }
                        if(student && course)
                        {
                            student -> dropCourse(course);
                        }
                        else
                        {
                            cout << "Student or course not found." << endl;
                        }
                        break;
                    }
                    case 3:
                    {
                        cout << "Enter student ID: ";
                        getline(cin, studentID);
                        for(auto student : students)
                        {
                            if(student -> get("studentID") == studentID)
                            {
                                student -> viewCourses();
                                break;
                            }
                        }
                        break;
                    }
                    default:
                    {
                        cout << "Invalid choice. Please enter a number between 1 and 3." << endl;
                    }
                }
                break;
            }
           
            case 2:
            {
                // Proceed as Teacher
                cout << "\nTeacher Functionality Menu:" << endl;
                cout << "1. Assign Course" << endl;
                cout << "2. Remove Course" << endl;
                cout << "3. View Courses Taught" << endl;
                cout << "Enter your choice: ";
                int teacherChoice;
                cin >> teacherChoice;
                cin.ignore(); // Clear the input buffer

                string teacherID, courseCode;
                switch(teacherChoice)
                {
                    case 1:
                    {
                        cout << "Enter teacher ID: ";
                        getline(cin, teacherID);
                        cout << "Enter course code: ";
                        getline(cin, courseCode);
                        Teacher* teacher = nullptr;
                        Course* course = nullptr;
                        for(auto t : teachers)
                        {
                            if (t -> get("teacherID") == teacherID)
                            {
                                teacher = t;
                                break;
                            }
                        }
                        for(auto c : courses)
                        {
                            if(c -> get("courseCode") == courseCode)
                            {
                                course = c;
                                break;
                            }
                        }
                        if(teacher && course)
                        {
                            teacher -> assignCourse(course);
                        }
                        else
                        {
                            cout << "Teacher or course not found." << endl;
                        }
                        break;
                    }
                    case 2:
                    {
                        cout << "Enter teacher ID: ";
                        getline(cin, teacherID);
                        cout << "Enter course code: ";
                        getline(cin, courseCode);
                        Teacher* teacher = nullptr;
                        Course* course = nullptr;
                        for(auto t : teachers)
                        {
                            if(t -> get("teacherID") == teacherID)
                            {
                                teacher = t;
                                break;
                            }
                        }
                        for(auto c : courses)
                        {
                            if(c -> get("courseCode") == courseCode)
                            {
                                course = c;
                                break;
                            }
                        }
                        if(teacher && course)
                        {
                            teacher -> removeCourse(course);
                        }
                        else
                        {
                            cout << "Teacher or course not found." << endl;
                        }
                        break;
                    }
                    case 3:
                    {
                        cout << "Enter teacher ID: ";
                        getline(cin, teacherID);
                        for (auto teacher : teachers) {
                            if (teacher -> get("teacherID") == teacherID)
                            {
                                teacher -> viewCourses();
                                break;
                            }
                        }
                        break;
                    }
                    default:
                    {
                        cout << "Invalid choice. Please enter a number between 1 and 3." << endl;
                    }
                }
                break;
            }

            case 3:
            {
                // Proceed as Course
                cout << "\nCourse Functionality Menu:" << endl;
                cout << "1. Add Student to Course" << endl;
                cout << "2. Remove Student from Course" << endl;
                cout << "3. View Enrolled Students" << endl;
                cout << "Enter your choice: ";
                int courseChoice;
                cin >> courseChoice;
                cin.ignore(); // Clear the input buffer

                string courseCode, studentID;
                switch(courseChoice)
                {
                    case 1:
                    {
                        cout << "Enter course code: ";
                        getline(cin, courseCode);
                        cout << "Enter student ID: ";
                        getline(cin, studentID);
                        Course* course = nullptr;
                        Student* student = nullptr;
                        for(auto c : courses)
                        {
                            if(c -> get("courseCode") == courseCode)
                            {
                                course = c;
                                break;
                            }
                        }
                        for(auto s : students)
                        {
                            if(s -> get("studentID") == studentID)
                            {
                                student = s;
                                break;
                            }
                        }
                        if(course && student)
                        {
                            course->addStudent(student);
                        }
                        else
                        {
                            cout << "Course or student not found." << endl;
                        }
                        break;
                    }
                    case 2:
                    {
                        cout << "Enter course code: ";
                        getline(cin, courseCode);
                        cout << "Enter student ID: ";
                        getline(cin, studentID);
                        Course* course = nullptr;
                        Student* student = nullptr;
                        for(auto c : courses)
                        {
                            if(c -> get("courseCode") == courseCode)
                            {
                                course = c;
                                break;
                            }
                        }
                        for(auto s : students)
                        {
                            if(s -> get("studentID") == studentID)
                            {
                                student = s;
                                break;
                            }
                        }
                        if(course && student)
                        {
                            course -> removeStudent(student);
                        }
                        else
                        {
                            cout << "Course or student not found." << endl;
                        }
                        break;
                    }
                    case 3:
                    {
                        cout << "Enter course code: ";
                        getline(cin, courseCode);
                        for(auto c : courses)
                        {
                            if(c -> get("courseCode") == courseCode)
                            {
                                c -> viewStudents();
                                break;
                            }
                        }
                        break;
                    }
                    default:
                    {
                        cout << "Invalid choice. Please enter a number between 1 and 3." << endl;
                    }
                }
                break;
            }
            case 4:
                // Register a new student
                registerStudent(students);
                break;
            case 5:
                // Register a new teacher
                registerTeacher(teachers);
                break;
            case 6:
                // Register a new course
                registerCourse(courses);
                break;
            case 7: 
            {
                // Exit the program
                // Save data to file before exiting
                saveData(students, teachers, courses);
                cout << "Exiting program." << endl;
                // Cleanup dynamic memory
                for(auto student : students)
                { 
                    delete student;
                }
                for(auto teacher : teachers)
                {
                    delete teacher;
                }
                for(auto course : courses)
                {
                    delete course;
                }
                return 0;
            }
            default: 
            {
                cout << "Invalid choice. Please enter a number between 1 and 4." << endl;
            }
        }
    }
    return 0;
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
            file << "Student: " << student -> get("studentID") << "," << student -> get("name") << "," << student -> get("email") << endl;
        }
        for(auto teacher : teachers)
        {
            file << "Teacher: " << teacher -> get("teacherID") << "," << teacher -> get("name") << "," << teacher -> get("email") << endl;
        }
        for(auto course : courses)
        {
            file << "Course: " << course -> get("courseCode") << "," << course -> get("courseName") << "," << course -> get("maxCapacity") << endl;
        }
        file.close();
        cout << "Data saved successfully." << endl;
    }
    else
    {
        cout << "Unable to open file." << endl;
    } 
}

string trim(const string& str)
{
    size_t start = str.find_first_not_of(" \t\n\r\f\v");
    size_t end = str.find_last_not_of(" \t\n\r\f\v");
    if(start == string::npos || end == string::npos)
    {
        return "";
    }
    return str.substr(start, end - start + 1);
}
// Function to register a new student
void registerStudent(vector<Student*>& students)
{
    string studentID, name, email;
    cout << "Enter student ID: ";
    getline(cin, studentID);
    cout << "Enter student name: ";
    getline(cin, name);
    cout << "Enter student email: ";
    getline(cin, email);
    students.push_back(new Student(studentID, name, email));
    cout << "Student registered successfully." << endl;
}

// Function to register a new teacher
void registerTeacher(vector<Teacher*>& teachers)
{
    string teacherID, name, email;
    cout << "Enter teacher ID: ";
    getline(cin, teacherID);
    cout << "Enter teacher name: ";
    getline(cin, name);
    cout << "Enter teacher email: ";
    getline(cin, email);
    teachers.push_back(new Teacher(teacherID, name, email));
    cout << "Teacher registered successfully." << endl;
}

// Function to register a new course
void registerCourse(vector<Course*>& courses)
{
    string courseCode, courseName;
    int maxCapacity;
    cout << "Enter course code: ";
    getline(cin, courseCode);
    cout << "Enter course name: ";
    getline(cin, courseName);
    cout << "Enter maximum capacity for the course: ";
    cin >> maxCapacity;
    cin.ignore(); // Clear the input buffer
    courses.push_back(new Course(courseCode, courseName, maxCapacity));
    cout << "Course registered successfully." << endl;
}