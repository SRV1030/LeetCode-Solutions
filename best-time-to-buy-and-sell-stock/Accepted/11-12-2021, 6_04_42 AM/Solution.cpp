// https://leetcode.com/problems/best-time-to-buy-and-sell-stock

class Solution {
public:
    int maxProfit(vector<int>& p) {
        int n=p.size();
        int mx=p[n-1],pr=0;
        for(int i=n-2;i>=0;i--){
            if(p[i]>=mx){
                mx=p[i];
            }else{
                pr=max(pr,mx-p[i]);
            }
        }
        return pr;
    }
};