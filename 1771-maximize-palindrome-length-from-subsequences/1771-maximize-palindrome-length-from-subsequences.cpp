class Solution {
public:
     int longestPalindrome(string w1, string w2) {
        int sz = w1.size() + w2.size(), sz1 = w1.size(), res = 0;
        auto s = w1 + w2;
        vector<vector<int>> dp(sz + 1, vector<int>(sz + 1));
        for (int len = 1; len <= s.size(); ++len) 
            for (auto i = 0; i + len <= s.size(); ++i) 
                if (s[i] == s[i + len - 1]) {
                    dp[i][i + len] = dp[i + 1][i + len - 1] + (len == 1 ? 1 : 2);
                    if (i < sz1 && i + len > sz1)
                        res = max(res, dp[i][i + len]);
                }
                else
                    dp[i][i + len] = max(dp[i][i + len - 1],  dp[i + 1][i + len]);
        return res;
    }
};