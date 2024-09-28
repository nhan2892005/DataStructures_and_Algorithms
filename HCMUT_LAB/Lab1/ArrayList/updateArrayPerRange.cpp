/*
Given an array of integers nums and a two-dimension array of integers operations.
Each operation in operations is represented in the form {L, R, X}. When applying an operation, all elements with index in range [L, R] (include L and R) increase by X.
Your task is to implement a function with following prototype:
vector<int> updateArrayPerRange(vector<int>& nums, vector<vector<int>>& operations);
The function returns the array after applying all operation in operations.

Note:
- The iostream, and vector libraries have been included and namespace std is being used. No other libraries are allowed.
- You can write helper functions.

For example:

Test	
vector<int> nums {13, 0, 6, 9, 14, 16};
vector<vector<int>> operations {{5, 5, 16}, {3, 4, 0}, {0, 2, 8}};
printVector(updateArrayPerRange(nums, operations));

Result
[21, 8, 14, 9, 14, 32]
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> updateArrayPerRange(vector<int>& nums, vector<vector<int>>& operations) {
    int n = nums.size();
    vector<int> diff(n + 1, 0); 
    
    for (const auto& op : operations) {
        int L = op[0], R = op[1], X = op[2];
        diff[L] += X;
        if (R + 1 < n) {
            diff[R + 1] -= X;
        }
    }
    
    int increment = 0;
    for (int i = 0; i < n; ++i) {
        increment += diff[i]; 
        nums[i] += increment; 
    }
    
    return nums;
}

void printVector(const vector<int>& nums) {
    cout << "[";
    for (int i = 0; i < nums.size(); ++i) {
        cout << nums[i];
        if (i < nums.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]";
}

int main() {
    vector<int> nums {13, 0, 6, 9, 14, 16};
    vector<vector<int>> operations {{5, 5, 16}, {3, 4, 0}, {0, 2, 8}};
    printVector(updateArrayPerRange(nums, operations));
    return 0;
}