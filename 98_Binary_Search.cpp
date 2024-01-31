#include<iostream>
using namespace std;

int binarySearch(int arr[], int left, int right, int val){
    int mid;
    while(left <= right){
        mid = (left+right)/2;

        if(val > arr[mid]){
            left = mid+1;
        }
        else if(val < arr[mid]){
            right = mid-1;
        }
        else{
            return mid;
        }
    }
    return -1;
}

int main()
{
     int arr[] = {12,43,56,76,87,99,100,233};
     int arrSize = sizeof(arr)/sizeof(int);

     cout << "Index : " << binarySearch(arr,0,arrSize-1,87);

    return 0 ;
}