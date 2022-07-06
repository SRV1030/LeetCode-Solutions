class Solution {
public:
    int md=1e9+7;
    int countPalindromicSubsequences(string s) {
        int n=s.size();
        vector<vector<long long int>>dp(n,vector<long long int>(n));
        vector<int>prev(n),next(n);
        unordered_map<char,int>mp;
        for(int i=0;i<n;i++){
            if(mp.count(s[i])) prev[i]=mp[s[i]];
            else prev[i]=-1;
            mp[s[i]]=i;
        }
        mp.clear();
        for(int i=n-1;i>=0;i--){
            if(mp.count(s[i])) next[i]=mp[s[i]];
            else next[i]=-1;
            mp[s[i]]=i;
        }
        for(int g=0;g<n;g++){
            for(int i=0,j=g;j<n;j++,i++){
                if(g==0) dp[i][j]=1;
                else if(g==1)dp[i][j]=2;
                else{
                    if(s[i]==s[j]){
                        if(next[i]>prev[j])dp[i][j]=(2*dp[i+1][j-1]+2)%md;
                        else if(next[i]==prev[j])dp[i][j]=(2*dp[i+1][j-1]+1)%md;
                        else dp[i][j]=((2*dp[i+1][j-1])%md-(dp[next[i]+1][prev[j]-1])%md)%md;
                    }
                    else dp[i][j]=(dp[i+1][j]%md+dp[i][j-1]%md-dp[i+1][j-1]%md)%md;
                }
                if(dp[i][j]<0)
                        dp[i][j]+=md;
            }
        }
        return dp[0][n-1];
    }
};