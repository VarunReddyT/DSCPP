#include<iostream>
#include<stack>
using namespace std;

bool checkPalindrome(string s){
    stack<char> st;
    int length = s.size();

    int mid = length/2;

    for(int i = 0; i<mid; i++){
        st.push(s[i]);
    }
    int i = mid;
    if(length%2 != 0){
        i += 1;
    }
    char elem;
    while(i<length){
        elem = st.top();
        st.pop();

        if(elem != s[i]){
            return false;
        }
        i++;
    }
    return true;
}

int main()
{
    string s = "madm";
    if(checkPalindrome(s)){
        cout << "Palindrome";
    }
    else{
        cout << "Not Palindrome";
    }
    return 0 ;
}