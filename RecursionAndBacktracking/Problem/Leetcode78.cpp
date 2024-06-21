#include "leetcode_problem.h"

void Solution::dfs(const vector<int>& nums, int s, vector<int>&& path, vector<vector<int>>& ans) {
    ans.push_back(path);

    for (int i = s; i < nums.size(); ++i) {
      path.push_back(nums[i]);
      dfs(nums, i + 1, move(path), ans);
      path.pop_back();
    }
}

vector<vector<int>> Solution::subsets(vector<int>& nums) {
    vector<vector<int>> ans;
    dfs(nums, 0, {}, ans);
    return ans;
}