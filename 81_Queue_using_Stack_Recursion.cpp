// Dequeue Costly using one stack and recursion

#include<iostream>
#include<stack>
using namespace std;

stack<int> s1,s2;


void display(){
     int a = s1.top();
     s1.pop();
     if(s1.empty()){
        s1.push(a);
        cout << a << " ";
        return;
     }
    display();  
    cout << a << " ";
    s1.push(a);
}


void dequeue(){
    int a = s1.top();
    s1.pop();
    if(s1.empty()){
        return;
    }
    dequeue();
    s1.push(a);
}


int main()
{
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(40);
    s1.push(50);
    s1.push(60);

    display();
    cout << endl;
    dequeue();

    display();

    return 0 ;
}