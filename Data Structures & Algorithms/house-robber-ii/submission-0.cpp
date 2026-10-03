class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }
        int max1 = robHelper(nums, 0, n - 2);
        int max2 = robHelper(nums, 1, n - 1);
        return max(max1, max2);
    }

private:
    int robHelper(vector<int>& nums, int start, int end) {
        int rob1 = 0;
        int rob2 = 0;
        
        for (int i = start; i <= end; i++) {
            int temp = max(nums[i] + rob1, rob2);
            rob1 = rob2;
            rob2 = temp;
        }
        
        return rob2;
    }
};