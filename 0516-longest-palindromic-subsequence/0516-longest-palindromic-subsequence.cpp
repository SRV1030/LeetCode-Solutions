class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int sz1=s.size();
        vector<vector<int>> dp(sz1 + 1, vector<int>(sz1 + 1));
        for (int len = 1; len <= s.size(); ++len) 
            for (auto i = 0; i + len <= s.size(); ++i) 
                if (s[i] == s[i + len - 1]) {
                    dp[i][i + len] = dp[i + 1][i + len - 1] + (len == 1 ? 1 : 2);
                }
                else
                    dp[i][i + len] = max(dp[i][i + len - 1],  dp[i + 1][i + len]);
        return dp[0][sz1];
    }
};

