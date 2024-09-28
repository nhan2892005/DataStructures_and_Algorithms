/*
Given a string S of characters, a duplicate removal consists of choosing two adjacent and equal letters, and removing them.

We repeatedly make duplicate removals on S until we no longer can.

Return the final string after all such duplicate removals have been made.

Included libraries: vector, list, stack
*/

#include <iostream>
#include <vector>
#include <list>
#include <stack>
using namespace std;

string removeDuplicates(string S) {
    stack<char> st;
    for(char c : S){
        if(!st.empty() && st.top() == c){
            st.pop();
        }else{
            st.push(c);
        }
    }
    string res = "";
    while(!st.empty()){
        res = st.top() + res;
        st.pop();
    }
    return res;
}

int main(){
    string S = "abbaca";
    cout << removeDuplicates(S);
    return 0;
}