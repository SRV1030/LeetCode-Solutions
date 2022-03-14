// https://leetcode.com/problems/maximum-length-of-pair-chain

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end());
        vector<int>dp;
        for(auto&p:pairs){
            auto itr=lower_bound(dp.begin(),dp.end(),p[0]);
            if(itr==dp.end())dp.push_back(p[1]);
            else if(*itr>p[1])*itr=p[1];
        }
        return dp.size();
    }
};