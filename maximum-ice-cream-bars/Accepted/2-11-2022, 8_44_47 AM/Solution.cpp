// https://leetcode.com/problems/maximum-ice-cream-bars

class Solution {
public:
    int maxIceCream(vector<int>& costs, int cns) {
        sort(costs.begin(),costs.end());
        int ic=0;
        long long coins=cns;
        for(auto&i:costs){
            if(coins>=i)ic++;
            coins-=i;
        }
        return ic;
    }
};