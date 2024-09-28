/*
Given an array of integers.
Your task is to implement a function with following prototype:
int sumOfMaxSubarray(vector<int>& nums, int k);
The function returns the sum of the maximum value of every consecutive subarray of nums with fixed length k.

Note:
- The iostream, vector, queue and deque libraries have been included and namespace std is being used. No other libraries are allowed.
- You can write helper functions and classes.

For example:

Test	                                                        Result
vector<int> nums {1, 2, 4, 3, 6};                               13
int k = 3;
cout << sumOfMaxSubarray(nums, k);
*/

#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int sumOfMaxSubarray(vector<int>& nums, int k) {
    int n = nums.size();
    deque<int> dq;
    int sum = 0;
    for(int i = 0; i < n; i++){
        while(!dq.empty() && dq.front() < i - k + 1){
            dq.pop_front();
        }
        while(!dq.empty() && nums[dq.back()] < nums[i]){
            dq.pop_back();
        }
        dq.push_back(i);
        if(i >= k - 1){
            sum += nums[dq.front()];
        }
    }
    return sum;
}

int main(){
    vector<int> nums {1, 2, 4, 3, 6};
    int k = 3;
    cout << sumOfMaxSubarray(nums, k);
    return 0;
}