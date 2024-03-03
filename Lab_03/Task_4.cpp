#include <iostream>
#include <vector>
#include <string>
using namespace std;

class task
{
public:
    string description;
    bool completed;
    task(string desc) : description(desc), completed(false) {}
};

class to_do_list
{
    vector<task*> tasks;
public:
    void add_task(const string &desc) { tasks.push_back(new task(desc)); }
    
    void list_tasks()
    {
        cout << "\nTasks:" << endl;
        for(size_t i = 0; i < tasks.size(); ++i)
        {
            if(tasks[i] -> completed == false)
            {
                cout << i + 1 << ". ";
            }
            else if(tasks[i] -> completed)
            {
                cout << "\n[DONE] ";
            }
            cout << tasks[i] -> description << endl;
        }
    }
    
    void mark_task_completed(size_t index)
    {
        if(index >= 0 && index < tasks.size())
        {
            tasks[index] -> completed = true;
            cout << "\nTask marked as completed: " << tasks[index] -> description << endl;
        }
        else
        {
            cout << "\nInvalid task index." << endl;
        }
    }
    
    ~to_do_list()
    {
        for(task *task : tasks)
        {
            delete task;
        }
    }
};

int main()
{
    to_do_list myList;
    myList.add_task("Finish Lab 3");
    myList.add_task("Prepare for presentation");
    myList.list_tasks();
    myList.mark_task_completed(1);
    myList.list_tasks();
    
    return 0;
}
