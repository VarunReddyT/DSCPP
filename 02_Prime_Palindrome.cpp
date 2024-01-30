// Check whether a number is prime and palindrome.

#include<iostream>
#include<math.h>
using namespace std;

bool prime(int num);
bool palindrome(int num);
int main()
{
    for(int i = 1; i<=1000; i++){
        if(prime(i) && palindrome(i)){
            cout << i <<"\n";
        }
    }
    return 0 ;
}

bool prime(int num){
    if (num>=2){
        for(int i = 2; i<=sqrt(num); i++){
            if(num%i == 0){
                return false;
            }
        }
    }
    else{
        return false;
    }
    return true;
}


bool palindrome(int num){
    int temp = num;
    int rem;
    int newNum = 0;
    while(temp != 0){
        rem = temp%10;
        newNum = newNum*10 + rem;
        temp = temp/10;
    }
    if(newNum == num){
        return true;
    }
    return false;
}