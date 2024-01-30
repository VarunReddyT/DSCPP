#include<iostream>
#include<string.h>
using namespace std;

int main()
{
    string s = "kmit";
    string s1 = "kmit1";

    cout << s.append(s1)<<endl;
    s.assign(s1);
    cout << s << endl;
    cout << s.at(2) << endl; 
    
    return 0 ;
}