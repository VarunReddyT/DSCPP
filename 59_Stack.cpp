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

class Stack{
    Node * top;
    public:
        Stack(){
            top = NULL;
        }
        void push(int);
        void pop();
        int peek();
        bool isEmpty();
        void display();
};


void Stack :: push(int val){
    Node * temp = new Node(val);

    if(!temp){
        cout << "Stack Overflow" << endl;
        return;
    }

    temp->next = top;
    top = temp;
}

void Stack :: pop(){
    Node * temp = top;
    if(top == NULL){
        cout << "Stack Underflow" << endl;
        return;
    }
    top = temp->next;
}

int Stack :: peek(){
    if(top == NULL){
        cout << "Stack Underflow" << endl;
        return 0;
    }
    return top->val;
}

void Stack :: display(){
    Node * temp = top;
    if(top == NULL){
        cout << "Stack Underflow" << endl;
        return;
    }
    while(temp != NULL){
        cout << temp->val << endl;
        temp = temp->next;
    }
}

bool Stack :: isEmpty(){
    return top == NULL;
}
int main()
{
    Stack Stack;
    cout << Stack.isEmpty() << endl;
    Stack.push(10);
    Stack.push(20);
    Stack.push(30);
    Stack.pop();
    Stack.push(40);
    Stack.push(50);
    Stack.push(60);
    Stack.push(70);
    Stack.pop();
    Stack.display();
    int a = Stack.peek();  // Top most element
    cout << "Peek element is : " << a;
    return 0 ;
}