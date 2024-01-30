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
        void display();
        void update(int,int);
};

void LinkedList :: insertAtHead(int val){
    Node * new_node = new Node(val);
    new_node->next = head;
    head = new_node; 
}


void LinkedList :: display(){
    Node * temp = head;
    while(temp != NULL){
        cout << temp->val << endl;
        temp = temp->next;
    }
}

void LinkedList :: update(int val,int pos){
    Node * temp = head;
    int i = 0;
    while(i != pos){
        i++;
        temp = temp->next;
    }
    temp->val = val;
}



int main()
{

    LinkedList LinkedList(10);
    LinkedList.insertAtHead(20);
    LinkedList.insertAtHead(30);
    LinkedList.insertAtHead(40);
    LinkedList.insertAtHead(50);
    LinkedList.insertAtHead(60);
    LinkedList.insertAtHead(70);
    LinkedList.display();
    LinkedList.update(99,2);
    cout << "After updation :" << endl;
    LinkedList.display();
    return 0 ;
}