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

    void display()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << endl;
            temp = temp->next;
        }
        
    }
    void add(int data)
    {
        Node *newNode = new Node(data);
        Node *temp = head;
        if(head == NULL){
            head = newNode;
            return;
        }
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
};

int main()
{
    LinkedList linkedlist;
    int arr[5] = {3,1,63,5,67};
    for(int i = 0; i<4; i++){
        for(int j = i; j<5; j++){
            if(arr[i] > arr[j]){
                swap(arr[i],arr[j]);
            }
        }
    }
    for(int i = 0; i<5; i++){
        linkedlist.add(arr[i]);
    }

    linkedlist.display();
    return 0;
}