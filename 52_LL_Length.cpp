#include<iostream>
using namespace std;

class Node{
    public:
        int val;
        Node* next;
        Node(int data){
            val = data;
            next = NULL;
        }
};

class LinkedList{
    private:
        Node* head;
    public:
        LinkedList(int data){
            Node * n = new Node(data);
            head = n;
            n->next = NULL;
        }
        void insertAtHead(int);
        int length();
};

void LinkedList :: insertAtHead(int val){
    Node * new_node = new Node(val);
    new_node->next = head;
    head = new_node;
}

int LinkedList :: length(){
    Node * temp = head;
    int len = 0;
    while(temp){
        len++;
        temp = temp->next;
    }
    return len;
}
int main()
{
    LinkedList LinkedList(10);
    LinkedList.insertAtHead(20);
    LinkedList.insertAtHead(30);
    LinkedList.insertAtHead(40);
    LinkedList.insertAtHead(50);
    int l = LinkedList.length();
    
    return 0 ;
}