#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class LinkedList
{
public:
    Node *head = NULL;

    void createNode(int data)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            return;
        }
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void display()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << endl;
            temp = temp->next;
        }
        
    }

    int length(){
        Node * temp = head;
        int i = 0;

        while(temp != NULL){
            i++;
            temp = temp->next;
        }

        return i;
    }

    void addAtBeginning(int data)
    {
        Node *newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    void addAtEnd(int data)
    {
        Node *newNode = new Node(data);
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void addAtPos(int data, int pos)
    {
        Node *newNode = new Node(data);
        Node *temp = head;
        for (int i = 1; i < pos; i++)
        {
            temp = temp->next;
            if (temp == NULL)
            {
                createNode(data);
                return;
            }
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void deleteNode(int data){
        Node * temp = head;
        Node * prev;
        if(head == NULL){
            cout << "Empty List" << endl;
            return;
        }
        while(temp != NULL){
            if(temp->data == data){
                if(temp == head){
                    head = temp->next;
                }
                else{
                    prev->next = temp->next;
                }
                return;
            }
            prev = temp;
            temp = temp->next;
        }
    }
};

int main()
{
    LinkedList linkedlist;
    int x, ch, ele, pos;
    while (1)
    {
        cout << "\n1.Create\n";
        cout << "2.Display\n";
        cout << "3.Insertion_at_begin\n";
        cout << "4.Insert_at_position\n";
        cout << "5.Delete\n";
        cout << "6.length\n";
        cout << "7.exit\n";
        cout << "Enter choice\n";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "Enter a value\n";
            cin >> x;
            linkedlist.createNode(x);
            break;
        case 2:
            linkedlist.display();
            break;
        case 3:
            cout << "Enter a value\n";
            cin >> x;
            linkedlist.addAtBeginning(x);
            break;
        case 4:
            cout << "Enter a value\n";
            cin >> x;
            cout << "enter the position\n";
            cin >> pos;
            linkedlist.addAtPos(x, pos);
            break;
        case 5:
            cout << "Enter a element to delete\n";
            cin >> ele;
            linkedlist.deleteNode(ele);
            break;
        case 6:
            cout << "Length of Linked List : " <<linkedlist.length() << endl;
            break;
        case 7:
            break;
        }
    }
    return 0;
}