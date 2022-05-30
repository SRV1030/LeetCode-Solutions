class Solution {
public:
    int maxProfit(vector<int>& p) {
        int n=p.size(),ans=0,chp=p[0];
        for(int i=1;i<n;i++){
            ans=max(ans,p[i]-chp);
            chp=min(chp,p[i]);
        }
        return ans;        
    }
};