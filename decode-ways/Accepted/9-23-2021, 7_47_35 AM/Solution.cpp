// https://leetcode.com/problems/decode-ways

class Solution {
public:
    int numDecodings(string s) {
        if(s[0]=='0') return 0;
        int n=s.length();
        int dp[n];
        dp[0]=1;
        for(int i=1;i<n;i++){
            if(s[i-1]=='0' && s[i]=='0') dp[i]=0;
            else if(s[i-1]=='0' && s[i]!='0')dp[i]=dp[i-1];
            else if(s[i-1]!='0' && s[i]=='0'){
                if(s[i-1]=='1'|| s[i-1]=='2') dp[i]=i-2>=0?dp[i-2]:1;
                else dp[i]=0;
            }
            else{
                string z="";
                z+=s[i-1];
                z+=s[i];
                if(stoi(z)<=26)dp[i]=dp[i-1]+(i-2>=0?dp[i-2]:1);
                else dp[i]=dp[i-1];
            }
        }
        return dp[n-1];
    }
};