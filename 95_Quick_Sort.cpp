#include<iostream>
using namespace std;

void printArray(int arr[], int sizeArr){
    for(int i = 0; i<sizeArr; i++){
        cout << arr[i] << " ";
    }
}

int partition(int arr[],int lb, int ub){
    int pivot = arr[lb];
    int start = lb;
    int end = ub;

    while(start < end){
        while(arr[start] <= pivot){
            start++;
        }
        while(arr[end] > pivot){
            end--;
        }
        if(start < end){
            swap(arr[start],arr[end]);
        }
    }
    swap(arr[lb],arr[end]);
    return end;
}

void quickSort(int arr[], int lb, int ub){
    if(lb<ub){
        int loc = partition(arr,lb,ub);
        quickSort(arr,lb,loc-1);
        quickSort(arr,loc+1,ub);
    }
}

int main()
{
    int arr[] = {123,43,1,43,224,42,45,65,34,666,21};
    int arrSize = sizeof(arr)/sizeof(int);

    quickSort(arr,0,arrSize-1);
    printArray(arr,arrSize);
    return 0 ;
}