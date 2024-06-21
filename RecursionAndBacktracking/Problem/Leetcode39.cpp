#include "leetcode_problem.h"

void Solution::dfs(vector<int>& candidates, 
                        vector<int> &comb, 
                        int i, int tot, int target, 
                        vector<vector<int>> &ans) {
    if(tot == target) {
        ans.push_back(comb);
        return;
    }
    if(i >= candidates.size() || tot > target) {
            return;
        }
        comb.push_back(candidates[i]);
        dfs(candidates, comb, i, tot + candidates[i], target, ans);
        comb.pop_back();
        dfs(candidates, comb, i + 1, tot, target, ans);
    }

vector<vector<int>> Solution::combinationSum(vector<int>& candidates, int target) {
    vector<vector<int >> ans;
    vector<int> comb;
    dfs(candidates, comb, 0, 0, target, ans);
    return ans;
}