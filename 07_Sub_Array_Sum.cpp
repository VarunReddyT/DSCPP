#include<iostream>
using namespace std;

int main()
{
    int sum = 0;
    int num;
    cin >> num;
    int arr[5] = {1,2,3,4,5};
    for(int i = 0; i<5; i++){
        sum = 0;
        for(int j = i; j<5; j++){
            for(int k = i; k<=j;k++){
                sum += arr[k];
            }
        }
        if(sum == num){
            cout << "Yes" << endl;
        }
        cout << sum;
        cout<<endl;
    }
    
    return 0 ;
}