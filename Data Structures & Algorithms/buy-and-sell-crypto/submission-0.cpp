class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minprices = prices[0];
        int profit=0;
        for(int i =0;i<prices.size();i++){
            minprices = min(minprices , prices[i]);
            profit = max(profit , prices[i]-minprices);
        }
        return profit;
        
    }
};
