// https://leetcode.com/problems/largest-divisible-subset

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& a) {
        vector<int>ans;
        int n=a.size();
        if(n==0) return ans;
        sort(a.begin(),a.end());
        int ind=0;
        vector<int>dp(n,0);
        vector<int>p(n,-1);
        dp[0]=1;
        for(int i=1;i<n;i++){
            dp[i]=1;
            for(int j=0;j<i;j++){
                if(a[i]%a[j]==0 && dp[j]+1>dp[i]){
                    dp[i]=dp[j]+1;
                    p[i]=j;
                }
                if(dp[i]>dp[ind])ind=i;
            }
        }
        while(ind>=0){
            ans.push_back(a[ind]);
            ind=p[ind];            
        }
        return ans;
    }
};