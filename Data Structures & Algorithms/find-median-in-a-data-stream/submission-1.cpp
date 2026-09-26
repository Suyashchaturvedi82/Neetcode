class MedianFinder {
    private:
    std::priority_queue<int> maxheap;
    std::priority_queue<int,std::vector<int>,std::greater<int>> minheap;

public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        maxheap.push(num);
        minheap.push(maxheap.top());
        maxheap.pop();
        if(minheap.size()>maxheap.size()){
            maxheap.push(minheap.top());
            minheap.pop();
        }
        
    }
    
    double findMedian() {
        if(maxheap.size()>minheap.size()){
            return maxheap.top();
        }
        return (maxheap.top()+ minheap.top())/2.0;
    }
};
