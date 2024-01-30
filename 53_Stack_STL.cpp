#include<iostream>
#include<stack>
using namespace std;

int main()
{
    stack<int> Stack;
    cout << Stack.empty() << endl;
    Stack.push(10);
    Stack.push(20);
    Stack.push(30);
    Stack.pop();
    Stack.push(40);
    Stack.push(50);
    Stack.push(60);
    Stack.push(70);
    Stack.pop();
    int a = Stack.top();  // Top most element
    cout << "Peek element is : " << a << endl;
    while(!Stack.empty()){
        cout << Stack.top() << endl;
        Stack.pop();
    }
    return 0 ;
}