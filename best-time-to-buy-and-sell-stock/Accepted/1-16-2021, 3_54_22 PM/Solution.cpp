// https://leetcode.com/problems/best-time-to-buy-and-sell-stock

class Solution {
public:
    int maxProfit(vector<int>& a) {
        int r=a.size(),mx=0;
        if(r==1) return 0;
        int i=0,j=1;
        while(j<r){
            if(a[i]<a[j]) mx=max(mx,a[j]-a[i]);
            else i=j;
            j++;
            
        }
        return mx;        
    }
};