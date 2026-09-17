class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>st;
        int maxarea = 0;
        for(int i = 0;i<=heights.size();i++){
            int currHeight=(i==heights.size())?0:heights[i];
            while(!st.empty()&&currHeight<heights[st.top()]){
                int h = heights[st.top()];
                st.pop();
                int width;
                if(st.empty()){
                    width = i;
                }
                else{
                    width = i-st.top()-1;
                }
                int area = h*width;
                maxarea = max(maxarea,area);

            }
            st.push(i);
        }
        return maxarea;
    }
};
