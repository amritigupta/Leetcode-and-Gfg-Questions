class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int size;
    
    
    KthLargest(int k, vector<int> nums) {
        size=k;
        for(int i=0;i<nums.size();i++) {
            pq.push(nums[i]);
            //removes the minimum element
            if(pq.size()>k) pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        //removes the minimum element
        if(pq.size()>size) pq.pop();
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */