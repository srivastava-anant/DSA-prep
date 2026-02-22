class Solution {
public:

    void findCombination(int ind, int target, vector<int>& arr,
                         vector<vector<int>>& ans, vector<int>& ds) {

        // target achieved
        if (target == 0) {
            ans.push_back(ds);
            return;
        }

        for (int i = ind; i < arr.size(); i++) {

            // skip duplicates
            if (i > ind && arr[i] == arr[i - 1])
                continue;

            // if element exceeds target → stop exploring further
            if (arr[i] > target)
                break;

            // choose element
            ds.push_back(arr[i]);

            // move forward (each element used once)
            findCombination(i + 1, target - arr[i], arr, ans, ds);

            // backtrack
            ds.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort(candidates.begin(), candidates.end());

        vector<vector<int>> ans;
        vector<int> ds;

        findCombination(0, target, candidates, ans, ds);

        return ans;
    }
};

