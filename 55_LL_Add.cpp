#include<iostream>
#include<cmath>
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
        void update(LinkedList,LinkedList,int);
        int lengthL();
        int lengthLL(int);
};

void LinkedList :: insertAtHead(int val){
    Node * new_node = new Node(val);
    new_node->next = head;
    head = new_node; 
}


void LinkedList :: display(){
    Node * temp = head;
    while(temp->next != NULL){
        cout << temp->val << "->";
        temp = temp->next;
    }
    cout << temp->val;
    
    cout << endl;
}

void LinkedList :: update(LinkedList LinkedList2,LinkedList LinkedList3, int a){
    Node * temp = head;
    Node * temp2 = LinkedList2.head;
    Node * temp3 = LinkedList3.head;
    int i = a;
    int sumL = 0;
    int carry = 0;
    int sumN = 0;
    int n = 0;
    while(i > 0){
        int b = lengthLL(temp->val + temp2->val);
        
        if(b != 1){
            carry = 1;
            sumL = sumL + pow(10,i);
            sumN = sumN + pow(10,i);
            carry = 0;  
        }


        sumL += ((temp->val + temp2->val)%10)*(pow(10,i-1));

        sumN += ((temp->val + temp2->val)%10)*(pow(10,i-1));
        cout << sumN << endl;
        sumN = 0;

        i--;
        temp = temp->next;
        temp2 = temp2->next;
    }
    
    cout << sumL << endl;
}

int LinkedList :: lengthLL(int val){
    int i = 0;
    while(val != 0){
        i++;
        val /= 10;
    }
    return i;
}
int LinkedList :: lengthL(){
    Node * temp = head;
    int i = 0;
    while(temp != NULL){
        i++;
        temp = temp->next;
    }
    return i;
}

int main()
{

    LinkedList LinkedList1(9);
    LinkedList1.insertAtHead(4);
    LinkedList1.insertAtHead(7);
    LinkedList LinkedList2(3);
    LinkedList2.insertAtHead(4);
    LinkedList2.insertAtHead(5);
    LinkedList1.display();
    LinkedList2.display();
    LinkedList LinkedList3(0);
    int a = LinkedList1.lengthL();
    LinkedList1.update(LinkedList2,LinkedList3, a);
    // LinkedList3.display();
    return 0 ;
}