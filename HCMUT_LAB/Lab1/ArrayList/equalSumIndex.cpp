/*
Given an array of integers.
Your task is to implement a function with following prototype:
int equalSumIndex(vector<int>& nums);
The function returns the smallest index i such that the sum of the numbers to the left of i is equal to the sum of the numbers to the right.
If no such index exists, return -1.

Note:
- The iostream and vector libraries have been included and namespace std is being used. No other libraries are allowed.
- You can write helper functions.

For example:

Test	                                                Result
vector<int> nums {3, 5, 2, 7, 6, 4};                    3
cout << equalSumIndex(nums);
*/

#include <iostream>
#include <vector>
using namespace std;

int equalSumIndex(vector<int>& nums) {
    int totalSum = 0;
    int leftSum = 0;

    for (int num : nums) {
        totalSum += num;
    }
    for (int i = 0; i < nums.size(); ++i) {
        int rightSum = totalSum - leftSum - nums[i];

        if (leftSum == rightSum) {
            return i; 
        }

        leftSum += nums[i];
    }

    return -1;
}

int main() {
    vector<int> nums {3, 5, 2, 7, 6, 4};
    cout << equalSumIndex(nums);
    return 0;
}