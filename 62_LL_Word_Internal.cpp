#include<iostream>
using namespace std;

class Node{
    public:
        char val;
        Node * link;
        Node(char data){
            val = data;
            link = NULL;
        }
};
class Node2{
    public:
        string val;
        Node2 * link;
        Node2(string data){
            val = data;
            link = NULL;
        }
};

class Stack{
    Node * top;
    public:
        Stack(){
            top = NULL;
        }
        void push(char);
        Node * pop();
        void display();
};
class Stack2{
    Node2 * top;
    public:
        Stack2(){
            top = NULL;
        }
        void push(string);
        Node * pop();
        void display();
};


void Stack2 :: push(string val){
    Node2 * temp = new Node2(val);
    temp->link = top;
    top = temp;
}

void Stack :: push(char val){
    Node * temp = new Node(val);
    temp->link = top;
    top = temp;
}

Node * Stack :: pop(){
    char a;
    Node * temp = top;
    top = temp->link;
    return temp;
}

void Stack :: display(){
    Node * temp = top;
    while(temp != NULL){
        cout << temp->val << " ";
        temp = temp->link;
    }
}
void Stack2 :: display(){
    Node2 * temp = top;
    while(temp != NULL){
        cout << temp->val << " ";
        temp = temp->link;
    }
}


int main()
{
    Stack Stack1;
    string s;
    cin >> s;
    string b = "";
    for(int i = s.length()-1; i>=0; i--){
        Stack1.push(s[i]);
    }
    Stack1.display();
    cout << endl;

    for(int i = 0; i<s.length(); i++){
        Node * a = Stack1.pop();
        b = a->val + b;
    }
    cout << b << endl;

    Stack2 Stack2;
    string sentence;
    int count = 0;
    string word = "";
    sentence = "moon is far away";
    for(int i = 0; i<sentence.length() ; i++){
        if(sentence[i] == ' '){
            Stack2.push(word);
            word = "";
            count ++;
        }
        else{
            word = word + sentence[i];
        }
    } 
    Stack2.push(word);
    Stack2.display();

    return 0 ;
}