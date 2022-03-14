// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii

class Solution {
public:
    int maxProfit(vector<int>& p) {
        int n=p.size();
        int pr=0;
        for(int i=0;i<n-1;i++){
            if(p[i+1]>p[i]) pr+=p[i+1]-p[i];
        }
        return pr;
    }
};