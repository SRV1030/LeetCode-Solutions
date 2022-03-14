// https://leetcode.com/problems/k-diff-pairs-in-an-array

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int c=0;
        for(auto i:nums){
            if(i==INT_MAX)continue;
            auto it=find(nums.begin(),nums.end(),i+k);
            if(it!=nums.end()){
                i=INT_MAX;
                nums[it-nums.begin()]=INT_MAX;
                c++;
            }            
        }
            
        return c;
        
    }
};