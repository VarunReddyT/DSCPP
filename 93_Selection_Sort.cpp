#include<iostream>
using namespace std;

void printArray(int arr[], int sizeArr){
    for(int i = 0; i<sizeArr; i++){
        cout << arr[i] << " ";
    }
}

int main()
{
    int arr[] = {23,1,43,123,4,21,42};
    int sizeArr = sizeof(arr)/sizeof(int);
    int min_index;

    for(int i = 0; i<sizeArr-1; i++){
        min_index = i;
        for(int j = i+1; j<sizeArr; j++){
            if(arr[j] < arr[min_index]){
                min_index = j;
            }
        }

        if(i != min_index){
            swap(arr[i],arr[min_index]);
        }    
    }

    printArray(arr,sizeArr);
    return 0 ;
}