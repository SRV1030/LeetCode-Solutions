// https://leetcode.com/problems/subarray-sum-equals-k

class Solution {
public:
    int subarraySum(vector<int>& a, int k) {
        int c=0,mx=0;
        unordered_map<int,int>mp;
        mp[0]=1;
        for(auto& i:a){
            c+=i;
            if(mp.count(c-k))mx+=mp[c-k];
            mp[c]++;
        }
        return mx;
    }
};
