#include <iostream>
#include <string>
using namespace std;

string repeatString(const string& str, int n) {
    if (n == 0) return "";
    return str + repeatString(str, n - 1);
}

int findClosingParenthesis(const string& s, int openPos, int openCount = 1) {
    if (openCount == 0) return openPos - 1;
    if (s[openPos] == '(') return findClosingParenthesis(s, openPos + 1, openCount + 1);
    if (s[openPos] == ')') return findClosingParenthesis(s, openPos + 1, openCount - 1);
    return findClosingParenthesis(s, openPos + 1, openCount);
}

string expandHelper(const string& s, int i) {
    int n = s.length();
    if (i >= n) return ""; 
    
    if (isdigit(s[i])) { 
        int num = s[i] - '0'; 
        int openPos = i + 1; 
        int closePos = findClosingParenthesis(s, openPos + 1); 
        string inner = expandHelper(s.substr(openPos + 1, closePos - openPos - 1), 0); 
        return repeatString(inner, num) + expandHelper(s, closePos + 1); 
    } else { 
        return s[i] + expandHelper(s, i + 1); 
    }
}

string expand(string s) {
    return expandHelper(s, 0);
}

int main() {
    cout << expand("2(ab3(cde)x)") << "\n"; 
    cout << expand("2(x0(y))3(z)") << "\n";  
    return 0;
}
