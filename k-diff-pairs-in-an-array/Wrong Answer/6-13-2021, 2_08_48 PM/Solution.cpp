// https://leetcode.com/problems/k-diff-pairs-in-an-array

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
       set<pair<int,int>>s;        
        for(auto i:nums){
            if(i==INT_MAX)continue;
            auto it=find(nums.begin(),nums.end(),i+k);
            if(it!=nums.end())
                s.insert({min(i,*it),max(i,*it)});
                       
        }
            
        return s.size();
        
    }
};