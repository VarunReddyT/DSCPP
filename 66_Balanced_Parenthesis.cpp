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
        void display();
        bool isEmpty();
        int peek();
};

void Stack :: push(int val){
    Node * new_node = new Node(val);

    new_node->next = top;
    top = new_node;
}

void Stack :: pop(){
    top = top->next;
}

void Stack :: display(){
    Node * temp = top;
    while(temp != NULL){
        cout << temp->val << endl;
        temp = temp->next;
    }
}

int Stack :: peek(){
    return top->val;
}

bool Stack :: isEmpty(){
    return top == NULL;
}

int main()
{
    Stack stack;
    
    string s = "{[()]}";

    bool flag = true;

    for(int i = 0; i<s.size(); i++){
        if(flag == false){
            break;
        }
        if(s[i] == '{' || s[i] == '[' || s[i] == '('){
            stack.push(s[i]);
        }
        else{
            if(s[i] == '}'){
                if(stack.peek() == '{'){
                    stack.pop();
                }
                else{
                    flag = false;
                    break;
                }
            }
            else if(s[i] == ']'){
                if(stack.peek() == '['){
                    stack.pop();
                }
                else{
                    flag = false;
                    break;
                }
            }
            else if(s[i] == ')'){
                if(stack.peek() == '('){
                    stack.pop();
                }
                else{
                    flag = false;
                    break;
                }
            }
        }
    }

    if(stack.isEmpty()){
        cout << "Valid" << endl;
    }
    else{
        cout << "Invalid" << endl;
    }
    return 0 ;
}