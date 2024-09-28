/*
Given an array nums[] of size N having distinct elements, the task is to find the next greater element for each element of the array
Next greater element of an element in the array is the nearest element on the right which is greater than the current element.
If there does not exist a next greater of a element, the next greater element for it is -1

Note: iostream, stack and vector are already included

Constraints:
1 <= nums.length <= 10^5
0 <= nums[i] <= 10^9

Example 1:
Input:
nums = {15, 2, 4, 10}
Output:
{-1, 4, 10, -1}

Example 2:
Input:
nums = {1, 4, 6, 9, 6}
Output:
{4, 6, 9, -1, -1}
*/

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> nextGreater(vector<int> nums) {
    stack<int> s;
    vector<int> res(nums.size(), -1);
    for(int i = 0; i < nums.size(); i++){
        while(!s.empty() && nums[s.top()] < nums[i]){
            res[s.top()] = nums[i];
            s.pop();
        }
        s.push(i);
    }
    return res;
}

int main(){
    vector<int> nums = {15, 2, 4, 10};
    vector<int> res = nextGreater(nums);
    for(int i = 0; i < res.size(); i++){
        cout << res[i] << " ";
    }
    return 0;
}