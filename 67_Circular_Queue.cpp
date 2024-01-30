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
};

class Queue{
    Node * top;
    Node * last;
    public:
        Queue(){
            top = NULL;
            last = NULL;
        }

        void enqueue(int);
        void dequeue();
        bool isEmpty();
        void display();
        int sizeQ();
};


bool Queue :: isEmpty(){
    return (top == NULL);
}

int Queue :: sizeQ(){
    Node * temp = top;
    int i = 0;
    while(temp != NULL){
        i++;
        temp = temp->next;
    }
    return i;
}

void Queue :: enqueue(int val){
    Node * new_node = new Node(val);
    if(top == NULL){
        top = new_node;
        last = new_node;
        return;
    }
    last->next = new_node;
    last = new_node;
    last->next = top;

}

void Queue :: dequeue(){
    Node * temp = top;
    if(isEmpty()){
        cout << "Queue Underflow" << endl;
        return;
    }
    top = temp->next;
    last->next = top;

}

void Queue ::  display(){
    Node * temp = top;
    while(temp != last){
        cout << temp->val << endl;
        temp = temp->next;
    }
    cout << temp->val << endl;
}

int main()
{
    Queue queue;
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.enqueue(40);
    queue.enqueue(50);
    queue.enqueue(60);
    queue.enqueue(70);
    queue.enqueue(80);
    queue.enqueue(90);
    queue.enqueue(100);
    queue.enqueue(110);
    queue.enqueue(120);
    queue.dequeue();
    queue.display();
    return 0 ;
}

