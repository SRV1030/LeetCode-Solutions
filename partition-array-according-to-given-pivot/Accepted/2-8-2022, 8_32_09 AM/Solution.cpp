// https://leetcode.com/problems/partition-array-according-to-given-pivot

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int>gt;
        int j=0,cnt=0;
        for(auto&i:nums){
            if(i<pivot)nums[j++]=i;
            else if(i==pivot)cnt++;
            else gt.emplace_back(i);            
        }
        while(cnt--)nums[j++]=pivot;
        for(auto&i:gt)nums[j++]=i;
        return nums;
    }
};