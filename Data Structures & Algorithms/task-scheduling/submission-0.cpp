class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int>counts;
        for(const auto&task:tasks){
            counts[task]++;
        }
        priority_queue<int>maxheap;
        for(const auto&pair:counts){
            maxheap.push(pair.second);
        }
        queue<pair<int,int>>cooldown;
        int time =0;
        while(!maxheap.empty()||!cooldown.empty()){
            time++;
            if(!maxheap.empty()){
                int remaining_freq=maxheap.top()-1;
                maxheap.pop();
                if(remaining_freq>0){
                    cooldown.push({remaining_freq,time+n});
                }

            }
            if(!cooldown.empty()&&cooldown.front().second==time){
                maxheap.push(cooldown.front().first);
                cooldown.pop();
            }
        }
        return time;
        
    }
};
