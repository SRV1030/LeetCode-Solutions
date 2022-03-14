// https://leetcode.com/problems/range-sum-query-mutable

class NumArray {
public: vector<int>org;
    NumArray(vector<int>& nums) {
        org=nums;
    }
    
    void update(int index, int val) {
        if(index<0 || index>=org.size()) return;
        org[index]=val;
    }
    
    int sumRange(int left, int right) {
        int sum=0;
        for(int i=left;i<=right;i++)sum+=org[i];
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */