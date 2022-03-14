// https://leetcode.com/problems/distinct-subsequences

class Solution {
public:
    int dp[1005][1005];
    int fun(string& s, string& t, int i, int j)
    {
        if(j==t.size()) //we got the whole string t 
            return 1;
        if(i==s.size()) //we reached at the end of string s, but not found string t in it.
            return 0;
        if(dp[i][j]!=-1) 
            return dp[i][j];
        
        // if the letters at the current index in both the string are same, then move forward in both
        // the string and also check, if the letter at current index in string t, agains comes in 
        // string s. So, we are adding the two functions.
        if(s[i]==t[j])  
            return dp[i][j]=fun(s, t, i+1, j+1)+fun(s, t, i+1, j);
        
        // if the letters at the current index in string s and t does not match, then move ahed only, 
        // in string s, because we have to match the letter with the string t.
        else
            return dp[i][j]=fun(s, t, i+1, j);
    }
    int numDistinct(string s, string t) {
        memset(dp, -1, sizeof(dp));
        return fun(s, t, 0, 0);
    }
};

// https://www.youtube.com/watch?v=HtLVAvIGikU