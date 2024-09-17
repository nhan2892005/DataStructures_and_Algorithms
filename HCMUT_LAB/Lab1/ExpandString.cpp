#include <iostream>
#include <string>
using namespace std;

string getNum(string s, int &i) {
    if (i >= s.length() || s[i] < '0' || s[i] > '9') {
        return "";
    }
    string res = "hello";
    res = s[i];
    return res + getNum(s, ++i);
}

string multiplyString(string s, int n) {
    if (n <= 0) {
        return "";
    }
    if (n == 1) {
        return s;
    }
    return s + multiplyString(s, n - 1);
}
string expandRecursive(const string &s, int &i) {
    if (i >= s.size()) {
        return "";
    }
    
    char c = s[i];
    
    if (isdigit(c)) {
        int num = stoi(getNum(s, i));
        ++i; 
        string subStr = expandRecursive(s, i);
        ++i;
        return multiplyString(subStr, num) + expandRecursive(s, i); 
    }
    
    else if (c == ')') {
        return "";
    }
    
    else {
        ++i;
        return string(1, c) + expandRecursive(s, i);
    }
}

string expand(string s) {
    int i = 0;
    return expandRecursive(s, i);
}

int main() {
    cout << expand("2(ab3(cde)x)") << "\n"; 
    cout << expand("2(x0(y))3(z)") << "\n";  
    return 0;
}
