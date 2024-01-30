#include<iostream>
using namespace std;


class Node{
    public:
    int value;
    Node* next;
    Node(int data){
        value = data;
        next = NULL;
    }
};

void insertAtHead(Node* &head, int val){
    Node * new_node = new Node(val);
    new_node->next = head;
    head = new_node;
}

void insertAtEnd(Node* &head, int val){
    Node *last_node = new Node(val);
    Node *temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = last_node;

}
void display(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->value << endl;
        temp = temp->next;
    }
}
int main()
{
    Node * head = NULL;
    insertAtHead(head,10);
    insertAtHead(head,20);
    insertAtHead(head,30);
    insertAtEnd(head,60);
    display(head);
    return 0 ;
}