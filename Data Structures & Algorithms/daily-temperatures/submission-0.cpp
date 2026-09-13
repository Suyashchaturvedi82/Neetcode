class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();
        vector<int>result(n,0);
        stack<int>st;
        for(int i =0;i<n;i++){
            while(!st.empty()&&temp[i]>temp[st.top()]){
                int prevday = st.top();
                st.pop();
                result[prevday]=i-prevday;
            }
            st.push(i);
        }
        return result;
        
    }
};
