/*
Given a string s containing just the characters '(', ')', '[', ']', '{', and '}'. Check if the input string is valid based on following rules:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
For example:

String "[]()" is a valid string, also "[()]".
String "[])" is not a valid string.
Your task is to implement the function
bool isValidParentheses (string s){
   
}
Note: The library stack of C++ is included.
*/

#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isValidParentheses(string s)
{
    stack<char> st;
    for (char c : s)
    {
        if (c == '(' || c == '[' || c == '{')
        {
            st.push(c);
        }
        else
        {
            if (st.empty())
            {
                return false;
            }
            if (c == ')' && st.top() != '(')
            {
                return false;
            }
            if (c == ']' && st.top() != '[')
            {
                return false;
            }
            if (c == '}' && st.top() != '{')
            {
                return false;
            }
            st.pop();
        }
    }
    return st.empty();
}

int main()
{
    string s = "([])";
    cout << isValidParentheses(s);
    return 0;
}