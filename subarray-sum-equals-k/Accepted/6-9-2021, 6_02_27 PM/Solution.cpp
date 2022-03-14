// https://leetcode.com/problems/subarray-sum-equals-k

class Solution {
public:
    int subarraySum(vector<int>& a, int k) {
        int c=0;
        int cum=0;
        unordered_map<int,int> mp;
        mp[0]=1;
        for(auto i:a){
            cum+=i;
            if(mp.count(cum-k))c+=mp[cum-k];
            mp[cum]++;
        }
        return c;
    }
};