/*
Given string S representing a postfix expression, the task is to evaluate the expression and find the final value. Operators will only include the basic arithmetic operators like *, /, + and -.

Postfix expression: The expression of the form “a b operator” (ab+) i.e., when a pair of operands is followed by an operator.

For example: Given string S is  "2 3 1 * + 9 -". If the expression is converted into an infix expression, it will be 2 + (3 * 1) – 9 = 5 – 9 = -4.

Requirement: Write the function to evaluate the value of postfix expression.
*/

#include <iostream>
#include <stack>
#include <string>
#include <sstream>
using namespace std;

int evaluatePostfix(string S)
{
    stack<int> st;
    stringstream ss(S);
    string token;
    while (ss >> token)
    {
        if (token == "+" || token == "-" || token == "*" || token == "/")
        {
            int b = st.top();
            st.pop();
            int a = st.top();
            st.pop();
            if (token == "+")
            {
                st.push(a + b);
            }
            else if (token == "-")
            {
                st.push(a - b);
            }
            else if (token == "*")
            {
                st.push(a * b);
            }
            else if (token == "/")
            {
                st.push(a / b);
            }
        }
        else
        {
            st.push(stoi(token));
        }
    }
    return st.top();
}

int main()
{
    string S = "2 3 1 * + 9 -";
    cout << evaluatePostfix(S);
    return 0;
}