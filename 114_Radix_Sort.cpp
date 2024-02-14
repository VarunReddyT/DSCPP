#include<iostream>
using namespace std;

int getMax(int arr[], int n){
    int max = arr[0];
    for(int i = 0; i<n; i++){
        if(arr[i]>max){
            max = arr[i];
        }
    }
    return max;
}

void countSort(int arr[], int n, int place){   // Place indicates units,tens,hundreds.....
    int output[n];
    int count [10] = {0};

    for(int i = 0; i<n; i++){
        count[(arr[i]/place)%10]++;     // Increment the value in the count array by checking the digits in the actual array
    }

    for(int i = 1; i<10; i++){
        count[i] += count[i-1];     // Cumulative count
    }

    // Now we come from the end of arr

    for(int i = n-1; i>=0; i--){
        output[count[(arr[i]/place)%10]-1] = arr[i];         // Place the element in output array in the index = cumulative value
        count[(arr[i]/place)%10]--;
    }


    for(int i = 0; i<n; i++){
        arr[i] = output[i];
    }
}

void radixSort(int arr[], int n){
    int place,m;
    m = getMax(arr,n);

    for(place = 1; m/place > 0; place *= 10){
        countSort(arr,n,place);
    }
}
int main()
{
    int arr[] = {3,26,4,453,23,64,27,354,76,46};
    int n = 10;

    radixSort(arr,n);
    
    cout << "Sorted Array : " << endl;
    for(int i = 0; i<n; i++){
        cout << arr[i] << " ";
    }
    return 0 ;
}