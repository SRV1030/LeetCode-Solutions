// https://leetcode.com/problems/k-diff-pairs-in-an-array

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int c=0;
        set<int>s(nums.begin(),nums.end());
        for(auto i:s)
            if(s.find(i+k)!=s.end())c++;
        return c;
        
    }
};