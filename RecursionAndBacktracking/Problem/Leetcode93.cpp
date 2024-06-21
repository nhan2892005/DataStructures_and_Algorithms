#include "leetcode_problem.h"

bool Solution::isValidNumber(string s){
    return stoi(s)>=0 and stoi(s)<=255 and to_string(stoi(s))==s;
}

bool Solution::isValidIPAddress(string s){
    int n = s.size();
    s.push_back('.');
    int i = 0;
    while(i <= n){
        string temp;
        while(s[i] != '.'){
            temp.push_back(s[i++]);
        }
        i++;
        if(temp.size() >3 || !isValidNumber(temp)){
            return false;
        }
    }
    s.pop_back();
    return true;
}

void Solution::dfs(int idx, int dot, string& ds, string& s){
    int n = s.size();
    if(idx == n){
        if(isValidIPAddress(ds) and dot==0){
            ans.push_back(ds);
        }
        return;
    }
    ds.push_back(s[idx]);
    if(dot >= 1 && ds.back() != '.' && idx!=n-1){
        ds.push_back('.');
        dfs(idx + 1,dot - 1,ds,s);
        ds.pop_back();
    }
    dfs(idx + 1, dot, ds, s);
    ds.pop_back();
}

vector<string> Solution::restoreIpAddresses(string s) {
    string ds="";
    dfs(0,3,ds,s);
    return ans;
}