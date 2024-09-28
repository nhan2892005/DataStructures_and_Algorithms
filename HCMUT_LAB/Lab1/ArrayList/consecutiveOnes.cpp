/*
Given an array of integers.
Your task is to implement a function with the following prototype:
bool consecutiveOnes(vector<int>& nums);
The function returns if all the 1s appear consecutively in nums. If nums does not contain any elements, please return true

Note:
- The iostream and vector libraries have been included and namespace std are being used. No other libraries are allowed.
- You can write helper functions.
- Do not use global variables in your code.

For example:

Test	                                                        Result
vector<int> nums {0, 1, 1, 1, 9, 8};                            1
cout << consecutiveOnes(nums);
*/

#include <iostream>
#include <vector>
using namespace std;

bool consecutiveOnes(vector<int>& nums) {
    int n = nums.size();
    
    if (n == 0) {
        return true;  
    }
    
    int firstOne = -1, lastOne = -1;
    
    for (int i = 0; i < n; ++i) {
        if (nums[i] == 1) {
            if (firstOne == -1) {
                firstOne = i; 
            }
            lastOne = i; 
        }
    }
    
    if (firstOne == -1) {
        return true;
    }
    
    for (int i = firstOne; i <= lastOne; ++i) {
        if (nums[i] != 1) {
            return false;
        }
    }
    
    return true;
}

int main() {
    vector<int> nums {0, 1, 1, 1, 9, 8};
    cout << consecutiveOnes(nums);
    return 0;
}