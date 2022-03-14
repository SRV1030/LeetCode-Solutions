// https://leetcode.com/problems/minimum-cost-of-buying-candies-with-discount

class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end(),greater<>());
        int c=0;
        for(int i=0;i<cost.size();i+=3) c+=cost[i]+((i+1)<cost.size()?cost[i+1]:0);
        return c;
    }
};