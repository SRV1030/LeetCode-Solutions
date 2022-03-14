// https://leetcode.com/problems/k-diff-pairs-in-an-array

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
       set<pair<int,int>>s;   
        map<int,int>mp;
        for(auto i:nums){
            if(i==INT_MAX)continue;
            if(mp.count(i+k)) s.insert({min(i,i+k),max(i,i+k)});
            if(mp.count(i-k)) s.insert({min(i,i-k),max(i,i-k)});
            mp[i]++;
                       
        }
            
        return s.size();
        
    }
};