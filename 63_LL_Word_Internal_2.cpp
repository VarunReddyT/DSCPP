#include<iostream>
using namespace std;

class Node2{
    public:
        string val;
        Node2 * link;
        Node2(string data){
            val = data;
            link = NULL;
        }
};

class Stack2{
    Node2 * top;
    public:
        Stack2(){
            top = NULL;
        }
        void push(string);
        Node2 * pop();
        void display();
};


void Stack2 :: push(string val){
    Node2 * temp = new Node2(val);
    temp->link = top;
    top = temp;
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
    
    Stack2 Stack2;
    string sentence;
    int count = 0;
    string word = "";
    getline(cin,sentence);
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