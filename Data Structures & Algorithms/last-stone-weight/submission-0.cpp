class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        std::priority_queue<int>maxheap(stones.begin(),stones.end());
        while(maxheap.size()>1){
            int stone1=maxheap.top();
            maxheap.pop();
            int stone2 = maxheap.top();
            maxheap.pop();
            if(stone1!=stone2){
                maxheap.push(stone1-stone2);
            }
        }
        return maxheap.empty()?0:maxheap.top();
    }
};
