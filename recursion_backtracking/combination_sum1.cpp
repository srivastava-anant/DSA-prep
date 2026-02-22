class Solution {
public:

    void solve(int index, int target, vector<int>& candidates,
               vector<int>& path, vector<vector<int>>& ans) {

        // if target becomes 0 → valid combination
        if (target == 0) {
            ans.push_back(path);
            return;
        }

        // if index crosses array → stop
        if (index == candidates.size())
            return;

        // ----- TAKE the number -----
        if (candidates[index] <= target) {
            path.push_back(candidates[index]);

            // stay at same index (reuse allowed)
            solve(index, target - candidates[index], candidates, path, ans);

            // backtrack
            path.pop_back();
        }

        // ----- SKIP the number -----
        solve(index + 1, target, candidates, path, ans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        vector<vector<int>> ans;
        vector<int> path;

        solve(0, target, candidates, path, ans);

        return ans;
    }
};

