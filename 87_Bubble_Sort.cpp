// Bubble Sort

// n elements  -->  n-1 passes

// Worst Case - Number of swaps = (n*(n-1))/2

#include<iostream>
using namespace std;

void printArray(int arr[], int sizeArr){
    for(int i = 0; i<sizeArr; i++){
        cout << arr[i] << " ";
    }
}

int main()
{
    int arr[] = {2,12,9,4,23,13,23,90,45,65,3,1};

    int sizeArr = sizeof(arr)/sizeof(int);

    printArray(arr,sizeArr);
    cout << endl;

    for(int i = 0; i<sizeArr-1; i++){
        bool flag = false;  
        for(int j = i+1; j<sizeArr; j++){
            if(arr[i] > arr[j]){
                swap(arr[i],arr[j]);
                flag = true;
            }
        }
        if(flag == false){  // * Break loop if array is already sorted
            break;
        }
    }

    printArray(arr,sizeArr);
    return 0 ;
}