#include<iostream>
using namespace std;

class Node{
    public:
        int val;
        Node* next;
        Node(int data){
            this->val = data;
            this->next = NULL;
        }
};

class LinkedList{
    public:
        Node* head;
        LinkedList(){
            head = NULL;
        }
        void insert(int val){
            Node * newNode = new Node(val);
            if(head == NULL){
                head = newNode;
                return;
            }
            Node * temp = head;
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = newNode;
        }
        void display(){
            Node * temp = head;
            while(temp != NULL){
                cout << temp->val << " ";
                temp = temp->next;
            }
        }
};

Node * mergeLL(Node * head1, Node * head2,LinkedList &LL3){
    Node * temp1 = head1;
    Node * temp2 = head2;
    while(temp1 != NULL && temp2 != NULL){
        if(temp1->val < temp2->val){
            LL3.insert(temp1->val);
            temp1 = temp1->next;
        }
        else{
            LL3.insert(temp2->val);
            temp2 = temp2->next;
        }
    }
    while(temp1 != NULL){
        LL3.insert(temp1->val);
        temp1 = temp1->next;
    }
    while(temp2 != NULL){
        LL3.insert(temp2->val);
        temp2 = temp2->next;
    }

    return LL3.head;

}


int main()
{
    LinkedList LL1;
    LinkedList LL2;
    LinkedList LL3;
    LL1.insert(1);
    LL1.insert(2);
    LL1.insert(4);
    LL2.insert(1);
    LL2.insert(3);
    LL2.insert(4);

    LL1.display();
    cout << endl;
    LL2.display();
    cout << endl;
    LL3.head = mergeLL(LL1.head,LL2.head,LL3);

    LL3.display();
    return 0 ;
}