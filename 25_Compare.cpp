#include<iostream>
#include<string.h>
using namespace std;

int main()
{
    // string s = "kmit";
    string s;
    cin >> s;
    string s1 = "kmit";
    if(!s.compare(s1)){
        cout << "Equal";
    }
    cout << s.compare(s1); // Gives 0
    return 0 ;
}