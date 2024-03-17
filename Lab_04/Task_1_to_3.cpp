#include <iostream>
#include <list>

using namespace std;
// Task 1: Custom Linked List Operations
class Node 
{
    public:
        int data;
        Node *next;
        Node(int d) : data(d), next(nullptr) {}
};

class linked_list 
{
    public:
        Node *head;
        linked_list() : head(nullptr) {}

        // Append data to the linked list
        void append(int data)
        {
            Node *new_node = new Node(data);
            if(!head)
            {
                head = new_node;
            }
            else
            {
                Node *temp = head;
                while (temp -> next)
                {
                    temp = temp -> next;
                }
                temp -> next = new_node;
            }
        }

        // Search for a value in the linked list
        bool search(int key)
        {
            Node* current = head;
            while (current != nullptr)
            {
                if(current -> data == key)
                {
                    return true;
                }
                current = current -> next;
            }
            return false;
        }

        // Reverse the linked list
        void reverse()
        {
            Node *prev = nullptr;
            Node *current = head;
            Node *next = nullptr;
            while(current != nullptr)
            {
                next = current -> next;
                current -> next = prev;
                prev = current;
                current = next;
            }
            head = prev;
        }
};

// Task 2: Advanced list Usage
void custom_sort(list<int>& lst) 
{
    lst.sort();
}

list<int> merge_lists(const list<int>& list1, const list<int>& list2) 
{
    list<int> mergedList = list1;
    list<int> sortedList2 = list2; // Make a copy of list2 to keep the original list unchanged
    sortedList2.sort(); // Sort the copied list2
    mergedList.merge(sortedList2); // Merge sorted list2 into mergedList
    return mergedList;
}

// Task 3: Complex Data Management with Lists of Lists
void print_matrix(const list<list<int>>& matrix) 
{
    for (const auto& row : matrix)
    {
        for (int val : row)
        {
            cout << val << " ";
        }
        cout << endl;
    }
}

void add_row(list<list<int>>& matrix, const list<int>& newRow)
{
    matrix.push_back(newRow);
}

void delete_row(list<list<int>>& matrix, int index)
{
    auto it = matrix.begin();
    advance(it, index);
    matrix.erase(it);
}

int main()
{
    // Task 1: Custom Linked List Operations
    linked_list linked_list;
    linked_list.append(1);
    linked_list.append(2);
    linked_list.append(3);
    cout << "Search for 2 in linked list: " << linked_list.search(2) << endl;
    linked_list.reverse();

    // Task 2: Advanced list Usage
    list<int> list1 = {3, 5, 7};
    list<int> list2 = {2, 4, 6};
    custom_sort(list1);
    list<int> merged_list = merge_lists(list1, list2);

    // Task 3: Complex Data Management with Lists of Lists
    list<list<int>> matrix = 
    {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    print_matrix(matrix);
    add_row(matrix, {10, 11, 12});
    delete_row(matrix, 1);
    print_matrix(matrix);

    return 0;
}

