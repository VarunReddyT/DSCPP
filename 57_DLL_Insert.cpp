#include<iostream>
using namespace std;

class Node{
    public:
        int val;
        Node * next;
        Node * prev;
        Node(int data){
            val = data;
            next = NULL;
            prev = NULL;
        }
};


class DoublyLL{
    public:
        Node * head;
        Node * tail;

        DoublyLL(){
            head = NULL;
            tail = NULL;
        }
        void display();
        void insertAtHead(int);
        void insertAtK(int,int);
        void insertAtEnd(int);
};

void DoublyLL :: insertAtHead(int val){
    Node * new_node = new Node(val);
    if(head == NULL){
        head = new_node;
        tail = new_node;
        return;
    }
    new_node->next = head;
    head->prev = new_node;
    head = new_node;

}


void DoublyLL :: insertAtK(int val,int pos){
    Node * temp = head;
    Node * new_node = new Node(val);
    int i = 1;
    while(i < pos){
        temp = temp->next;
        i++;
    }

    Node * temp2 = temp->next;

    new_node->next = temp2;
    new_node->prev = temp;
    temp2->prev = new_node;
    temp->next = new_node;

}

void DoublyLL :: insertAtEnd(int val){
    Node * new_node = new Node(val);
    if(tail == NULL){
        head = new_node;
        tail = new_node;
        return;
    }
    tail->next = new_node;
    new_node->prev = tail;
    tail = new_node;    
}

void DoublyLL :: display(){
    // Node * temp = tail;  // From last
     Node * temp = head;  // From first
    while(temp != NULL){
        cout << temp->val << endl;
        temp = temp->next;
    }
}

int main()
{
    DoublyLL dll;
    
    dll.insertAtHead(10);
    dll.insertAtHead(20);
    dll.insertAtHead(30);
    dll.insertAtHead(40);
    dll.insertAtEnd(100);
    dll.insertAtK(60,3);
    dll.display();
    return 0 ;
}