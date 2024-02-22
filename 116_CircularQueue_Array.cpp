#include<iostream>
using namespace std;
#define N 5
int arr[N];
int front = -1;
int rear = -1;
void enqueue(int x){
    if((rear+1)%N == front){
        cout<<"Overflow"<<endl;
    }
    else if(front==-1 && rear==-1){
        front = rear = 0;
        arr[rear] = x;
    }
    else{
        rear = (rear+1)%N;
        arr[rear] = x;
    }
}
void dequeue(){
    if(front==-1 && rear==-1){
        cout<<"Undequeuerflow"<<endl;
    }
    else if(front==rear){
        front = rear = -1;
    }
    else{
        front=(front+1)%N;
    }
}
void display(){
    if(front==-1 && rear==-1){
        cout<<"Undequeuerflow"<<endl;
    }
    else{
        int i = front;
        while(i!=rear){
            cout<<arr[i]<<",";
            i = (i+1)%N;
        }
        cout<<arr[i]<<endl;
        }
}
int main()
{
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    display();
    enqueue(6);
    dequeue();
    display();
    dequeue();
    display();
    enqueue(6);
    display();
    enqueue(7);
    display();
    enqueue(8);
    dequeue();
    display();
    return 0;
}