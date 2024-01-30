#include<iostream>
using namespace std;


void insertH(int arr[], int &n, int val){
    arr[n] = val;
    int i = n;
    n = n + 1;
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

int main()
{
    int arr[100] = {10,7,8,5,6};
    int n = 5;                          // * Number of elements

    insertH(arr,n,9);

    printArray(arr,n);
    cout << endl;
    
    insertH(arr,n,20);
    printArray(arr,n);
    return 0 ;
}