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
            Node * temp = head;
            Node * newNode = new Node(val);
            if(head == NULL){
                head = newNode;
                return;
            }
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = newNode;
        }
        int middleNode(){
            Node * slow = head;
            Node * fast = head;

            while(fast && fast->next){
                slow = slow->next;
                fast = fast->next->next;
            }

            return slow->val;
        }
};
int main()
{
    LinkedList LL;
    LL.insert(10);
    LL.insert(20);
    LL.insert(30);
    LL.insert(40);
    LL.insert(50);
    LL.insert(60);
    LL.insert(70);
    cout << LL.middleNode();
    return 0 ;
}