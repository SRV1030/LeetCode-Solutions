// https://leetcode.com/problems/subarray-sum-equals-k

class Solution {
public:
    int subarraySum(vector<int>& a, int k) {
        unordered_map<int,int>mp;
        int s=0,mx=0;
        mp[0]=1;
        for(auto i:a){
            s+=i;
            if(mp.count(s-k))mx+=mp[s-k];
            mp[s]++;
        }
        return mx;
    }
};
