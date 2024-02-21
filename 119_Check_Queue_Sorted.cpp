#include <iostream>
#include <stack>
#include <queue>
using namespace std;

bool checkSorted(queue<int> &queue, int n)
{
    stack<int> stack;
    int expected = 1;
    int fnt;

    while (!queue.empty())
    {
        fnt = queue.front();
        queue.pop();

        if (fnt == expected)
        {
            expected++;
        }
        else
        {
            if (stack.empty())
            {
                stack.push(fnt);
            }
            else if (!stack.empty() && stack.top() < fnt)
            {
                return false;
            }
            else
            {
                stack.push(fnt);
            }
        }

        while (!stack.empty() && stack.top() == expected)
        {
            stack.pop();
            expected++;
        }
    }

    if (expected - 1 == n && stack.empty())
    {
        return true;
    }
    return false;
}

int main()
{
    queue<int> queue;
    char ans;
    int val;
    do
    {
        cout << "Enter value to be pushed:" << endl;
        cin >> val;
        queue.push(val);
        cout << "Do you want to add another element : press[y for yes and n for no]:";
        cin >> ans;
    } while (ans == 'y');
    int n = queue.size();
    
    if(checkSorted(queue,n)){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
    return 0;
}