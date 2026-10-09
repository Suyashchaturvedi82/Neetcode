class Solution {
   public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0];
        int currmax = nums[0];
        int currmin = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int n = nums[i];
            int tempmax = currmax * n;
            int tempmin = currmin*n;
             currmax = max({n, tempmax, tempmin});
             currmin = min({n, tempmax, tempmin});
            res = max(res, currmax);
        }
        return res;
    }
};
