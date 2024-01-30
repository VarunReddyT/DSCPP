#include<iostream>
using namespace std;


void insertH(int arr[], int &n, int val){
    arr[n] = val;
    int i = n;
    n = n + 1;

    // ! Or use max_heapify
    
    int parent;
    while(i > 1){
        parent = (i-1)/2;
        if(arr[parent] < arr[i]){
            swap(arr[parent],arr[i]);
            i = parent;
        }
        else{
            return;
        }
    }
}

void printArray(int arr[], int n){
    for(int i = 0; i<n; i++){
        cout << arr[i] << " ";
    }
}

void max_Heapify(int arr[], int n, int i)
{
    int largest = i;
    int leftChild = 2 * i + 1;
    int rightChild = 2 * i + 2;
    if (leftChild < n && arr[leftChild] > arr[largest])
    {
        largest = leftChild;
    }
    if (rightChild < n && arr[rightChild] > arr[largest])
    {
        largest = rightChild;
    }
    if (largest != i)
    {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        max_Heapify(arr, n, largest);
    }
}
void deleteH(int arr[], int &n, int val){
    arr[0] = arr[n-1];
    n = n-1;\
    max_Heapify(arr,n,0);
}


int main()
{
    int arr[100] = {10,7,8,5,6};
    int n = 5;                          // * Number of elements

    insertH(arr,n,9);

    printArray(arr,n);
    cout << endl;
    
    insertH(arr,n,20);
    printArray(arr,n);
    cout << endl;
    deleteH(arr,n,10);
    printArray(arr,n);
    return 0 ;
}