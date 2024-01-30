#include<iostream>
using namespace std;

class Node{
    public:
        int val;
        Node*next;
        Node(int data){  // For creating a new Node
            val = data;
            next = NULL;
        }
};

class LinkedList{ // Group of Nodes
    private:
        Node* head;
    public:
        LinkedList(int data){
            Node * n = new Node(data);
            head = n;
            n->next = NULL;
        }
        void insertAtHead(int);
        void insertAtEnd(int);
        void display();
};

void LinkedList :: insertAtHead(int val){
    Node * new_node = new Node(val);
    new_node->next = head;
    head = new_node; 
}
void LinkedList :: insertAtEnd(int val){
    Node * new_node = new Node(val);
    Node * temp = head;

    if(head == NULL){
        head = new_node;
        return;
    }

    while(temp->next != NULL){
        temp = temp->next;
    }
    
    temp->next = new_node;
}

void LinkedList :: display(){
    Node * temp = head;
    while(temp != NULL){
        cout << temp->val << endl;
        temp = temp->next;
    }
}

int main()
{
    LinkedList LinkedList(10);  
    LinkedList.insertAtHead(40);
    LinkedList.insertAtEnd(60);
    LinkedList.display();
    return 0 ;
}