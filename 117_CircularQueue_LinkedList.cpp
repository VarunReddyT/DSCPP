#include <iostream>
#define SIZE 100
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

class cirQueue
{
public:
    Node *front;
    Node *rear;
    cirQueue()
    {
        front = NULL;
        rear = NULL;
    }
    void insertion(int);
    void deletion();
    void display();
};

void cirQueue ::insertion(int val)
{
    Node *newNode = new Node(val);
    if (front == NULL)
    {
        front = newNode;
    }
    else
    {
        rear->next = newNode;
    }
    rear = newNode;
    rear->next = front;
}

void cirQueue ::deletion()
{
    Node *temp = front;
    if (front == NULL)
    {
        cout << "Queue is empty" << endl;
        return;
    }
    if (front == rear)
    {
        delete (temp);
        front = NULL;
        rear = NULL;
    }
    else
    {
        front = front->next;
        rear->next = front;
        delete (temp);
    }
}

void cirQueue ::display()
{
    Node *temp = front;
    Node *temp1 = NULL;
    if (front == NULL)
    {
        cout << "Queue is empty" << endl;
        return;
    }
    while (temp != temp1)
    {
        cout << temp->data << " ";
        temp = temp->next;
        temp1 = front;
    }
}

int main()
{
    cirQueue cqobj;
    int ch;
    int elem;
    do
    {
        cout << "\n\n\tMain Menu";
        cout << "\n##########################";
        cout << "\n1. Insert\n2. Delete\n3. Display\n4. Exit\n\nEnter Your Choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "Enter the value to be inserted : ";
            cin >> elem;
            cqobj.insertion(elem);
            cqobj.display();
            break;
        case 2:
            cqobj.deletion();
            break;
        case 3:
            cqobj.display();
            break;
        case 4:
            break;
        default:
            cout << "\n\nWrong Choice!!! Try Again.";
        }
    } while (ch != 4);
    return 0;
}