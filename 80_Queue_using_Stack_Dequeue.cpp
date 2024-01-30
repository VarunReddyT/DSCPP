// Dequeue Costly

#include<iostream>
#include<stack>
using namespace std;

stack<int> s1,s2;


void display(){
    stack<int> tempS = s1;
    while(!tempS.empty()){
        cout << tempS.top() << " ";
        tempS.pop();
    }
    cout << endl;
}


void dequeue(){
    if(s1.empty() && s2.empty()){
        cout << "Empty stack" << endl;
        return;
    }
    else if(!s1.empty()){
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }

        s2.pop();

        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }

        cout << "Queue after deletion : " << endl;
        display();
    }
}


int main()
{
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(40);
    s1.push(50);
    s1.push(60);

    dequeue();

    return 0 ;
}