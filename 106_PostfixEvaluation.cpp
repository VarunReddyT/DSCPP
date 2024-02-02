#include<iostream>
#include<stack>
using namespace std;

int evaluatePostfix(string s){
    stack<int> st;

    for(int i = 0; i<s.length(); i++){
        if(isdigit(s[i])){
            st.push(s[i] - '0'); // Converting character to integer
        }
        else{
            int num1 = st.top();
            st.pop();
            int num2 = st.top();
            st.pop();

            switch(s[i]){
                case '+':
                    st.push(num2+num1);
                    break;
                case '-':
                    st.push(num2-num1);
                    break;
                case '*':
                    st.push(num2*num1);
                    break;
                case '/':
                    st.push(num2/num1);
                    break;
                default:
                    cout << "Invalid" << endl;
                    break;
            }
        }
    }

    return st.top();
}

int main()
{
    string s = "231*+9-";

    cout << "Postfix Evaluation : " << evaluatePostfix(s) << endl;
    return 0 ;
}