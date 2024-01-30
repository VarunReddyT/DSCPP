#include<iostream>
using namespace std;


int fib(int n){
    if(n == 0 || n == 1){
        return n;
    } 
    int i = fib(n-1);
    int j = fib(n-2);
    cout << i << " " << j << endl;
    return i + j;
}
int main()
{
    cout << fib(5) << endl;
    return 0 ;
}