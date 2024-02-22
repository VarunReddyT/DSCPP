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
        LinkedList(){
            head = NULL;
        }
        void insertAtHead(int);
        void insertAtEnd(int);
        void insertAtK(int,int);
        void deleteAtK(int);
        void deleteHead();
        void deleteEnd();
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

void LinkedList :: insertAtK(int val, int pos){
    Node * temp = head;
    Node * new_node = new Node(val);
    for(int i = 0; i<pos-1; i++){
        temp = temp->next;
        if(temp == NULL){
            cout << "Out of range"<<endl;
            return;
        }
    }
    Node * temp1 = temp->next;

    temp->next = new_node;
    new_node->next = temp1;
  
}

void LinkedList :: deleteAtK(int pos){
    Node * temp = head;
    if(pos == 0){
        head = temp->next;
        return;
    }
    
    for(int i = 0; i<pos-1; i++){
        temp = temp->next;
        if(temp == NULL){
            cout << "Out of range"<<endl;
            return;
        }
    }
    Node * temp1 = temp->next;
    Node * temp2 = temp1->next;
    
    temp->next = temp2;
}

void LinkedList :: display(){
    Node * temp = head;
    while(temp != NULL){
        cout << temp->val << endl;
        temp = temp->next;
    }
}

void LinkedList :: deleteHead(){
    head = head->next;
}

void LinkedList :: deleteEnd(){
    Node * temp = head;
    Node * prev = NULL;
    while(temp->next != NULL){
        prev = temp;
        temp = temp->next;
    }
    delete temp;
    prev->next = NULL;

}

int main()
{
    LinkedList LinkedList;  
    LinkedList.insertAtHead(10);
    LinkedList.insertAtHead(40);
    LinkedList.insertAtEnd(60);
    LinkedList.insertAtEnd(80);
    LinkedList.insertAtEnd(110);
    LinkedList.insertAtEnd(70);
    cout << "Linked List is : " << endl;
    LinkedList.display();
    cout << "Linked List is : " << endl;
    LinkedList.deleteAtK(0);
    LinkedList.display();
    LinkedList.deleteHead();
    cout << "Linked List is : " << endl;
    LinkedList.display();
    LinkedList.deleteEnd();
    cout << "Linked List is : " << endl;
    LinkedList.display();
    return 0 ;
}