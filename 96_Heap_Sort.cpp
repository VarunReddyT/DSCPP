#include<iostream>
using namespace std;

void max_heapify(int arr[], int n, int i){
    int largest = i;
    int leftChild = 2*i+1;
    int rightChild = 2*i+2;

    if(leftChild < n && arr[leftChild] > arr[largest]){
        largest = leftChild;
    }
    if(rightChild < n && arr[rightChild] > arr[largest]){
        largest = rightChild;
    }

    if(largest != i){
        swap(arr[largest], arr[i]);
        max_heapify(arr,n,largest);
    }
}

void heapSort(int arr[], int n){
    for(int i = (n/2)-1; i>=0; i--){
        max_heapify(arr,n,i);
    }
    for(int i = n-1; i>=0; i--){
        swap(arr[0],arr[i]);
        max_heapify(arr,i,0);
    }
}

int main()
{
    int arr[10] = {20,12,35,15,10,80,30,17,2,11};
    heapSort(arr,10);
    for(int i=0;i<10;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0 ;
}