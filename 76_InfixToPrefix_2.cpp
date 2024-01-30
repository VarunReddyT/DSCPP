#include<iostream>
#include<stack>
#include<algorithm>
// #include<cctype>
using namespace std;

int prec(char c) {
	if (c == '^')
		return 3;
	else if (c == '/' || c == '*')
		return 2;
	else if (c == '+' || c == '-')
		return 1;
	else
		return -1;
}


char associativity(char c) {
	if (c == '^')
		return 'R';
	return 'L'; 
}
void infixToPrefix(string s){
    reverse(s.begin(), s.end());

    for(int i = 0; i<s.length(); i++){
        if(s[i] == '('){
            s[i] = ')';
        }
        else if(s[i] == ')'){
            s[i] = '(';
        }
    }

    stack<char> st;
    string output = "";
    for(int i = 0; i<s.size(); i++){
        if(isalpha(s[i]) || isdigit(s[i])){
            output += s[i];
        }
        else if(s[i] == '('){
            st.push(s[i]);
        }
        else if(s[i] == ')'){
            while (st.top() != '(') {
				output += st.top();
				st.pop();
			}
			st.pop();
        }
        // else if(!isalpha(s[i]) && !isdigit(s[i]) && s[i] != ')' ){
        //     st.push(s[i]);
        // }
        else {
			while (!st.empty() && prec(s[i]) < prec(st.top()) ||
				!st.empty() && prec(s[i]) == prec(st.top()) &&
				associativity(s[i]) == 'L') {
				output += st.top();
				st.pop();
			}
			st.push(s[i]);
		}
	}
    while (!st.empty()) {
    output += st.top();
    st.pop();
    }

    reverse(output.begin(), output.end());
    cout << output << endl;

}

int main()
{
    string exp = "a+b*c+d";
    infixToPrefix(exp);
    return 0 ;
}

