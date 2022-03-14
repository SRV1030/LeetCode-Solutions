// https://leetcode.com/problems/minimum-cost-of-buying-candies-with-discount

class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end(),greater<>());
        int c=0;
        for(int i=0;i<cost.size()-1;i+=3) c+=cost[i]+cost[i+1];
        return c;
    }
};