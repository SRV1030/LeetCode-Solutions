// https://leetcode.com/problems/two-city-scheduling

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(),costs.end(),[](vector<int> a,vector<int> b){return a[0]-a[1]<b[0]-b[1];});
        int j=0,s=0;
        for(j=0;j<costs.size()/2;j++)s+=costs[j][0];
        for(;j<costs.size();j++)s+=costs[j][1];
        return s;
    }
};