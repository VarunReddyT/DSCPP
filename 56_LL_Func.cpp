#include<iostream>
using namespace std;

class Node{
    public:
        int val;
        Node * next;
        Node(int data){
            val = data;
            next = NULL;
        }
        void insert();
        void display();
};


void insert(Node* &head,int val){
    Node * new_node = new Node(val);
    Node * temp = head;
    if (head == NULL) {
        head = new_node;
        return;
    }
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = new_node;
}

Node*reverse(Node * &head){
    Node * temp = head;
    Node * tail = head;
    while(tail != NULL){
        tail = tail->next;
    }
    int i = 0;
    int a = 5;
    cout << "k";
    while(i<a){
        insert(tail,tail->val);
        tail = tail->next;
        head = head->next;
        i++;
        cout << "h";
    }
}
void display(Node* head){
    Node * temp = head;
    while(temp != NULL){
        cout << temp->val<<endl;
        temp = temp->next;
    }
    cout << "NULL"<<endl;
}

int main()
{
    Node * head = NULL;
    insert(head,10);
    insert(head,20);
    insert(head,30);
    insert(head,40);
    insert(head,50);
    reverse(head);
    display(head);
    return 0 ;
}