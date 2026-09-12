class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0, right = heights.size()-1;
        int ans = 0;
        while(left<right){
            int width = right - left;
            int h = min(heights[left],heights[right]);
            int area = width *h;
            ans= max(ans,area);
            if(heights[left]<heights[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return ans;
        
    }
};
