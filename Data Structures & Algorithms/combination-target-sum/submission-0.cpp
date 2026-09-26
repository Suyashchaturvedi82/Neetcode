class Solution {
    private:
    void backtrack(vector<int>&nums,int target ,int index, vector<int>&currentcombo , vector<vector<int>>&result){
        if(target ==0){
            result.push_back(currentcombo);
            return ;
        }
        if(target<0 || index>=nums.size()){
            return ;
        }
        currentcombo.push_back(nums[index]);
        backtrack(nums,target-nums[index],index,currentcombo,result);
        currentcombo.pop_back();
        backtrack(nums,target,index+1,currentcombo,result);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>>result;
        vector<int>currentcombo;
        backtrack(nums,target,0,currentcombo,result);
        return result;
    }
};
