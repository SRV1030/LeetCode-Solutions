// https://leetcode.com/problems/find-center-of-star-graph

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int,int>mp;
        for(auto&i:edges){
            mp[i[0]]++;
            mp[i[1]]++;
        }
        int n=mp.size();
        for(auto&[k,v]:mp)
            if(v==n-1) return k;
        return -1;
    }
};