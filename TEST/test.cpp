#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Task {
public:
    string description;
    bool completed;
    Task(string desc) : description(desc), completed(false) {}
};

class TaskManager {
    vector<Task*> tasks;
public:
    void addTask(const string &desc) { tasks.push_back(new Task(desc)); }
    
    void displayTasks() {
        cout << "\nTasks:" << endl;
        for(size_t i = 0; i < tasks.size(); ++i) {
            if(!tasks[i]->completed) {
                cout << i + 1 << ". ";
            }
            else if(tasks[i]->completed) {
                cout << "\n[DONE] ";
            }
            cout << tasks[i]->description << endl;
        }
    }
    
    void markTaskCompleted(size_t index) {
        if(index >= 0 && index < tasks.size()) {
            tasks[index]->completed = true;
            cout << "\nTask marked as completed: " << tasks[index]->description << endl;
        }
        else {
            cout << "\nInvalid task index." << endl;
        }
    }
    
    ~TaskManager() {
        for(Task *task : tasks) {
            delete task;
        }
    }
};

int main() {
    TaskManager manager;
    manager.addTask("Complete Project A");
    manager.addTask("Prepare for Meeting");
    manager.displayTasks();
    manager.markTaskCompleted(1);
    manager.displayTasks();
    
    return 0;
}
