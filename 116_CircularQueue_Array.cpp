#include <iostream>
using namespace std;

int cirQueue[5];
int front = -1, rear = -1, n = 5;

void insertCQ(int val)
{
    if ((front == 0 && rear == n - 1) || front == rear + 1)
    {
        cout << "Queue Overflow" << endl;
        return;
    }
    if (front == -1)
    {
        front = 0;
        rear = 0;
    }
    else
    {
        if (rear == n - 1)
        {
            rear = 0;
        }
        else
        {
            rear = rear + 1;
        }
    }
    cirQueue[rear] = val;
}

void deleteCQ()
{
    if (front == -1)
    {
        cout << "Queue Underflow" << endl;
        return;
    }
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        if (front == n - 1)
        {
            front = 0;
        }
        else
        {
            front = front + 1;
        }
    }
}

void display()
{
    int f = front;
    int r = rear;

    if (front == -1)
    {
        cout << "Queue is empty" << endl;
        return;
    }
    cout << "Queue elements are : " << endl;

    if (f <= r)
    {
        while (f <= r)
        {
            cout << cirQueue[f] << " ";
            f++;
        }
    }
    else
    {
        while (f <= n - 1)
        {
            cout << cirQueue[f] << " ";
            f++;
        }
        f = 0;
        while (f <= r)
        {
            cout << cirQueue[f] << " ";
            f++;
        }
    }
    cout << endl;
}

int main()
{
    int ch, val;
    cout << "1)Insert\n";
    cout << "2)Delete\n";
    cout << "3)Display\n";
    cout << "4)Exit\n";
    do
    {
        cout << "Enter choice : " << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "Input for insertion: " << endl;
            cin >> val;
            insertCQ(val);
            break;
        case 2:
            deleteCQ();
            break;
        case 3:
            display();
            break;
        case 4:
            cout << "Exit\n";
            break;
        default:
            cout << "Incorrect!\n";
        }
    } while (ch != 4);
    return 0;
}