// https://leetcode.com/problems/maximum-product-of-the-length-of-two-palindromic-subsequences

class Solution {
public:
    int ans=1;
    unordered_map<string,int>mp;
    int lps(string s){
        int n=s.length();
        if(n==0)return 0;
        if(mp.count(s))return mp[s];
        vector<vector<int>>dp(n+1,vector<int>(n+1));
        string r=s;
        reverse(s.begin(),s.end());
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1]==r[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return mp[s]=dp[n][n];
    }
    void findpair(string s,string a,string b,int idx){
        if(idx==s.length()){
            ans=max(ans,lps(a)*lps(b));
            return ;
        }
        //when including the element in a
        findpair(s,a+s[idx],b,idx+1);
        //when including the element in b
        findpair(s,a,b+s[idx],idx+1);
    }
    int maxProduct(string s) {
        mp.clear();
        findpair(s,"","",0);
        return ans;
    }
};