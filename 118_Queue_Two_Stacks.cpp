#include <iostream>
#include <stack>
using namespace std;

class Queue
{
public:
    stack<int> s1, s2;
    void enQueue(int val)
    {
        s1.push(val);
    }

    void deQueue()
    {
        if (s1.empty() && s2.empty())
        {
            cout << "Queue is empty" << endl;
            return;
        }
        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int deletedVal = s2.top();
        s2.pop();
        cout << "Deleted " << deletedVal << endl;
    }

    void display()
    {
        stack<int> s3 = s2;
        while (!s3.empty())
        {
            cout << s3.top() << " ";
            s3.pop();
        }
    }
};

int main()
{
    Queue queue;
    int ch, ele;
    while (1)
    {
        cout << "\n1.Enqueue(insertion) 2.Dequeue(deletion) 3.Display 4. Exit \nEnter ur choice : ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "Enter the element to be inserted : ";
            cin >> ele;
            queue.enQueue(ele);
            break;
        case 2:
            queue.deQueue();
            break;
        case 3: 
            queue.display();
            break;
        case 4:
            exit(1);
        }
    }
    return 0;
}