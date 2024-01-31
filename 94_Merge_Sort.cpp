#include<iostream>
using namespace std;

void merge(int arr[], int l, int mid, int r){
    int brr[r+1];
    int i = l;
    int j = mid+1;
    int k = l;
    while(i<=mid && j<=r){
        if(arr[i]<=arr[j]){
            brr[k]=arr[i];
            i++;
            k++;
        }
        else{
            brr[k]=arr[j];
            j++;
            k++;
        }
    }
    if(i>mid){
        while(j<=r){
            brr[k]=arr[j];
            j++;
            k++;
        }
    }
    else{
        while(i<=mid){
        brr[k]=arr[i];
        i++;
        k++;
        }
    }
    for(k=l;k<=r;k++){
        arr[k]=brr[k];
    }
}

void printArray(int arr[], int sizeArr){
    for(int i = 0; i<sizeArr; i++){
        cout << arr[i] << " ";
    }
}

void mergeSort(int arr[], int l, int r){
    if(l>=r){
        return;
    }

    int mid = (l+r)/2;
    mergeSort(arr,l,mid);
    mergeSort(arr,mid+1,r);
    merge(arr,l,mid,r);
}

int main()
{
    int arr[] = {23,12,41,43,21,3,31,4};
    int sizeArr = sizeof(arr)/sizeof(int);

    mergeSort(arr,0,sizeArr-1);

    printArray(arr,sizeArr);
    return 0 ;
}