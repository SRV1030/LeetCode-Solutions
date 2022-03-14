// https://leetcode.com/problems/time-needed-to-buy-tickets

class Solution {
public:
    int timeRequiredToBuy(vector<int>& t, int k) {
        int ans=0;
        for(int i=0;i<t.size();i++){
            if(i<=k)ans+=min(t[k],t[i]);
            else ans+=min(t[k]-1,t[i]);
        }            
        return ans;        
    }
};