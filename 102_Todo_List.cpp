#include <iostream>
using namespace std;

class Node
{
public:
    string task;
    int priority;
    Node()
    {
        task = "";
        priority = -1;
    }
    Node(int priority, string task)
    {
        this->priority = priority;
        this->task = task;
    }
};

class TodoL
{
    void minHeapifyDown(int index)
    {
        int smallest = index;
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;

        if (leftChild < size && arr[leftChild].priority < arr[smallest].priority)
        {
            smallest = leftChild;
        }
        if (rightChild < size && arr[rightChild].priority < arr[smallest].priority)
        {
            smallest = rightChild;
        }
        if (smallest != index)
        {
            swap(arr[smallest], arr[index]);
            minHeapifyDown(smallest);
        }
    }

    void minHeapifyUp(int index)
    {
        while (index > 0)
        {
            int parent = (index - 1) / 2;
            if (arr[index].priority < arr[parent].priority)
            {
                swap(arr[index], arr[parent]);
                index = parent;
            }
            else
            {
                break;
            }
        }
    }

    public:
        Node *arr;
        int size;
        int capacity;

        TodoL()
        {
            size = 0;
            capacity = 10;
            arr = new Node[capacity];
        }

        void insert(string task, int priority)
        {
            Node *new_node = new Node(priority, task);
            if (size == capacity)
            {
                capacity = 2 * capacity;
                Node *newArr = new Node[capacity];
                for (int i = 0; i < size; i++)
                {
                    newArr[i] = arr[i];
                }
                delete[] arr;
                arr = newArr;
            }
            arr[size++] = *new_node;
            minHeapifyUp(size - 1);
        }

        string extractHighestPriority()
        {
            if (size > 0)
            {
                string mini = arr[0].task;
                swap(arr[0], arr[size - 1]);
                size--;
                minHeapifyDown(0);
                return mini;
            }
            else
            {
                return "ToDoList Underflow";
            }
        }

        void Display(){
            if(size<1){
                cout << "ToDoList Underflow" << endl;
                return;
            }
            for (int i = 0; i < size; ++i)
            {
                cout << arr[i].priority << " -> " << arr[i].task << endl;
            }
            cout << endl;
            return;
        }
};

int main()
{
    TodoL tdl;
    int choice = 1;
    while(choice){

        cout<<"Enter Task and Priorty of the element you want to add in the ToDoList : "<<endl;
        string task;
        int priority;
        cout<<"Task : ";
        cin>>task;
        cout<<"Priority : ";
        cin>>priority;
        tdl.insert(task,priority);
        int ch;
        cout<<"Enter again?(0 to quit, 1 to continue) : ";
        cin>>ch;
        choice = ch;
    }

    cout << "ToDoList" << endl;
    tdl.Display();

    cout << "ToDoList after Extracting Highest Priority : " << endl;
    cout<<"Highest Priority Task : "<<tdl.extractHighestPriority()<<endl<<endl;
    tdl.Display();

    tdl.insert("Youtube",5);
    cout << "ToDoList after adding a task of certain priority : " << endl;
    tdl.Display();
    return 0;
}