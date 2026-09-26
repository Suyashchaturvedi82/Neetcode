class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> currentSubset;
        backtrack(nums, 0, currentSubset, result);
        return result;
    }   
private:
    void backtrack(vector<int>& nums, int index, vector<int>& currentSubset, vector<vector<int>>& result) {
        if (index == nums.size()) {
            result.push_back(currentSubset);
            return;
        }
        currentSubset.push_back(nums[index]);
        backtrack(nums, index + 1, currentSubset, result);
        currentSubset.pop_back();
        backtrack(nums, index + 1, currentSubset, result);
    }
};