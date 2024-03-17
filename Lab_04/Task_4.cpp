#include <iostream>
#include <list>
#include <string>

using namespace std;
class To_do_list
{
private:
    string task;
    list<To_do_list> sub_tasks;

public:
    To_do_list(const string& t) : task(t) {}

    void add_sub_task(const string& subTask)
    {
        sub_tasks.push_back(To_do_list(subTask));
    }

    void display(int level = 0) const
    {
        for(int i = 0; i < level; ++i)
        {
           cout << "    ";
        }
        cout << "- " << task << endl;
        for(const auto& subTask : sub_tasks)
        {
            subTask.display(level + 1);
        }
    }
    auto get_sub_tasks()
    {
        return sub_tasks.begin();
    }
};

int main()
{
    To_do_list to_do_list("Main Task");
    to_do_list.add_sub_task("Subtask 1");
    to_do_list.add_sub_task("Subtask 2");
    to_do_list.add_sub_task("Subtask 3");

    auto sub_task2 = to_do_list.get_sub_tasks();
    advance(sub_task2, 1);
    sub_task2 -> add_sub_task("Subtask 2.1");
    sub_task2 -> add_sub_task("Subtask 2.2");
    

    to_do_list.display();

    return 0;
}