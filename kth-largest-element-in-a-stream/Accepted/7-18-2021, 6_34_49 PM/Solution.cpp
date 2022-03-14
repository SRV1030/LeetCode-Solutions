// https://leetcode.com/problems/kth-largest-element-in-a-stream

class KthLargest {
public: int r; priority_queue<int,vector<int>,greater<int>>pq;
    KthLargest(int k, vector<int>& nums) {
        for(auto i:nums)pq.push(i);
        r=k;
    }
    
    int add(int val) {
        pq.push(val);
        while(pq.size()>r)pq.pop();
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */