class KthLargest {
public:
int k_limit;
std::priority_queue<int,std::vector<int>,std::greater<int>>minheap;
    KthLargest(int k, vector<int>& nums) {
         k_limit=k;
        for(int num:nums){
            add(num);
        }
        
    }
    
    int add(int val) {
        minheap.push(val);
        if(minheap.size()>k_limit){
            minheap.pop();
        }
        return minheap.top();
        
    }
};
