// Middle Term of the linked list

#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node(int data){
            this->data = data;
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
        int length(){
            Node * temp = head;
            int i = 0;
            while(temp != NULL){
                i++;
                temp = temp->next;
            }
            return i;
        }

        int middleNode(){
            Node * temp = head;
            int i = length();
            // Return 2nd term from the two middle terms if length is odd
            int j = (i/2)+1;
            cout << j<< endl;
            int k = 1;
            while(k<j){
                k++;
                temp = temp->next;
            }
            return temp->data;
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