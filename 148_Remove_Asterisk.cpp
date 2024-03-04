// You are given a string s, which contains stars *.

// In one operation, you can:

// Choose a star in s.
// Remove the closest non-star character to its left, as well as remove the star itself.
// Return the string after all stars have been removed.

// Note:

// The input will be generated such that the operation is always possible.
// It can be shown that the resulting string will always be unique.
#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

int main()
{
    string s = "leet**cod*e";
    string s2 = "";
    stack<char> s1;
    for(int i = 0; i<s.size();i++){
        if(s[i] != '*'){
            s1.push(s[i]);
        }
        else{
            s1.pop();
        }
    }
    while(!s1.empty()){
        s2 += s1.top();
        s1.pop();
    }
    reverse(s2.begin(),s2.end());
    cout << s2 << endl;
    return 0;
}