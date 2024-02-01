#include<iostream>
#include<queue>
using namespace std;

int main()
{
    priority_queue<int> max_heap;
    max_heap.push(32);
    max_heap.push(4);
    max_heap.push(23);
    max_heap.push(42);
    max_heap.push(5);
    priority_queue<int> temp = max_heap;
    cout << "Max Heap :" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;

    // Min Heap

    priority_queue<int, vector<int>, greater<int>> min_heap;

    min_heap.push(32);
    min_heap.push(4);
    min_heap.push(23);
    min_heap.push(42);
    min_heap.push(5);
    priority_queue<int, vector<int>, greater<int>> tmp = min_heap;
    cout << "Min Heap :" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << tmp.top() << " ";
        tmp.pop();
    }
    return 0 ;
}