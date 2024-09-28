/*
A nice number is a positive integer that contains only 2's and 5's.
Some nice numbers are: 2, 5, 22, 25, 52, 55, ...
Number 2 is the first nice number.
Given an integer N, return the Nth nice number.
Note: iostream, vector, queue are already included for you.

Constraint:
1 <= n <= 10^6

Example 1:
Input:
n = 5
Output:
52

Explanation:
The sequence of nice numbers is 2, 5, 22, 25, 52, 55, ...
The 5th number in this sequence is 52

Example 2:
Input:
n = 10000
Output:
2255522252225
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

long long nthNiceNumber(int n) {
    queue<long long> q;
    q.push(2);
    q.push(5);
    long long res = 0;
    for(int i = 0; i < n; i++){
        res = q.front();
        q.pop();
        q.push(res*10 + 2);
        q.push(res*10 + 5);
    }
    return res;
}

int main(){
    int n;
    cin >> n;
    cout << nthNiceNumber(n);
    return 0;
}