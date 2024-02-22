#include <iostream>
#include <stack>
using namespace std;

int prec(char c)
{
    if (c == '^')
    {
        return 3;
    }
    else if (c == '*' || c == '/')
    {
        return 2;
    }
    else if (c == '+' || c == '-')
    {
        return 1;
    }
    return -1;
}

// char associativity(char c) {
//     if (c == '^')
//         return 'R';
//     return 'L'; 
// }

void infixToPostfix(string s)
{
    stack<char> st;
    string result;

    for(int i = 0; i<s.length(); i++){
        if(isalpha(s[i]) || isdigit(s[i])){
            result += s[i];
        }
        else if(s[i] == '('){
            st.push(s[i]);
        }
        else if(s[i] == ')'){
            while(!st.empty() && st.top() != '('){
                result += st.top();
                st.pop();
            }
            if(!st.empty()){
                st.pop();
            }
        }
        else{
            // while(!st.empty() && prec(s[i]) < prec(st.top()) || !st.empty() && prec(s[i]) == prec(st.top()) && associativity(s[i]) == 'L'){
            //     result += st.top();
            //     st.pop();
            // }
            while(!st.empty() && prec(st.top()) > prec(s[i])){
                result += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }

    cout << result << endl;
}

int main()
{
    string s = "a+b*(c+d-e)*(f+g*h)-i";

    infixToPostfix(s);
    return 0;
}