// https://leetcode.com/problems/range-sum-query-mutable

class NumArray {
public: vector<int> pre,org;
    NumArray(vector<int>& nums) {
        pre=nums;
        org=nums;
        for(int i=1;i<pre.size();i++)pre[i]=pre[i-1]+pre[i];
    }
    
    void update(int index, int val) {
        if(index<0 || index>=pre.size()) return;
        for(int i=index;i<pre.size();i++)pre[i]=pre[i]-org[index]+val;
        org[index]=val;
    }
    
    int sumRange(int left, int right) {
        return pre[right]-pre[left]+org[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */