// https://leetcode.com/problems/maximum-ice-cream-bars

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int ic=0;
        for(auto&i:costs){
            if(coins>=i)ic++;
            coins-=i;
        }
        return ic;
    }
};