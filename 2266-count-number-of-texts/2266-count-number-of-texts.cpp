class Solution {
public:
    int countTexts(string k) {
        vector<int>dp(k.size()+1);
        int md=1e9+7;
        dp[0]=1;
        for(int i=1;i<k.size()+1;i++){
            dp[i]=dp[i-1];
            int d=(k[i-1]=='7'||k[i-1]=='9')?4:3;
            for(int j=i-2;j>=0 && j>=i-d && k[i-1]==k[j]; j--)dp[i]=(dp[i]+dp[j])%md;    
        }
        return dp[k.size()];        
    }
};