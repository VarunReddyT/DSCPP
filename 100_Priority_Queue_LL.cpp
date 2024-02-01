#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        int priority;
        Node * next = NULL;
        Node(int data, int priority){
            this->data = data;
            this->priority = priority;
            this->next = NULL;
        }
};

class Queue{
    private:
        Node * front;
    public:
        Queue(int data, int priority){
            Node * new_node = new Node(data,priority);
            front = new_node;
        }
        Queue(){
            front = NULL;
        }

        void insert(int data, int priority){
            Node * new_node = new Node(data,priority);
            if(front == NULL || priority < front->priority){   // Priorty 1 > Priority 5
                new_node->next = front;
                front = new_node;
            }
            Node * temp = front;
            while(temp->next != NULL && temp->next->priority <= priority){
                temp = temp->next;
            }

            new_node->next = temp->next;
            temp->next = new_node;
        }

        void deleteN(){
            if(front == NULL){
                cout << "Queue Underflow" << endl;
                return;
            }
            Node * temp = front;
            front = front->next;
            delete temp;
        }

         void Display()
    {
        if (front == NULL){
            cout << "Queue is empty"<<endl;
            return;
        }
        Node *temp = front;
            cout << "Queue is :"<<endl;
            cout << "Priority , Item\n";
            while (temp!= NULL)
            {
                cout << temp->priority << " , " << temp->data << endl;
                temp = temp->next;
            }
    }
};

int main()
{
    Queue q1(10, 1);
    q1.Display();
    q1.insert(15, 3);
    q1.insert(20, 2);
    q1.insert(30, 4);
    q1.Display();
    q1.deleteN();
    q1.Display();
    q1.deleteN();
    q1.Display();
    return 0 ;
}