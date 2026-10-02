class Solution {
public:
void backtrack(vector<int>&nums,int start, vector<int>&current,vector<vector<int>>&result){
    result.push_back(current);
    for(int i = start;i<nums.size();i++){
        if(i>start && nums[i]==nums[i-1]){
            continue;
        }
        current.push_back(nums[i]);
        backtrack(nums,i+1,current,result);
        current.pop_back();

    }
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>current;
        vector<vector<int>>result;
        sort(nums.begin(),nums.end());
        backtrack(nums,0,current,result);
        return result;
        
    }
};
