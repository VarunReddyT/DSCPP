// * A C++ priority queue is a type of container adapter, specifically designed such that the first element of the queue is either the greatest or the smallest of all elements in the queue, and elements are in non-increasing or non-decreasing order (hence we can see that each element of the queue has a priority {fixed order}).

// * In C++ STL, the top element is always the greatest by default. We can also change it to the smallest element at the top. Priority queues are built on the top of the max heap and use an array or vector as an internal structure. In simple terms, STL Priority Queue is the implementation of Heap Data Structure.

// ^ std::priority_queue<int> pq;   -> Max Heap - default
// ^ Create min heap for priority queue -  priority_queue <int, vector<int>, greater<int>> gq;

// C++ program to demonstrate the use of priority_queue
#include <iostream>
#include <queue>
using namespace std;

// driver code
int main()
{
	int arr[6] = { 10, 2, 4, 8, 6, 9 };

	// defining priority queue
	priority_queue<int> pq;

	// printing array
	cout << "Array: ";
	for (auto i : arr) {
		cout << i << ' ';
	}
	cout << endl;
	// pushing array sequentially one by one
	for (int i = 0; i < 6; i++) {
		pq.push(arr[i]);
	}

	// printing priority queue
	cout << "Priority Queue: ";
	while (!pq.empty()) {
		cout << pq.top() << ' ';
		pq.pop();
	}

	return 0;
}
