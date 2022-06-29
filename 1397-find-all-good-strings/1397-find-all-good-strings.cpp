class Solution {
public:
    int dp[501][51][2][2] = {};
int dfs(const string &s1, const string &s2, const string &evil, int sp, int ep, bool l1, bool l2, const vector<int> &kmp) {
    if (ep == evil.size())
        return 0;
    if (sp == s1.size())
        return 1;
    if (!dp[sp][ep][l1][l2]) {
        for (char ch = (l1 ? s1[sp] : 'a'); ch <= (l2 ? s2[sp] : 'z'); ++ch) {
            auto n_ep = ep;
            while (n_ep > 0 && ch != evil[n_ep])
                n_ep = kmp[n_ep - 1];
            dp[sp][ep][l1][l2] = (dp[sp][ep][l1][l2] + 
                dfs(s1, s2, evil, sp + 1, ch == evil[n_ep] ? n_ep + 1 : 0, 
                    l1 & (ch == s1[sp]), l2 & (ch == s2[sp]), kmp)) % 1000000007;
        }
    }
    return dp[sp][ep][l1][l2];
}
int findGoodStrings(int n, string &s1, string &s2, string &evil) {
    vector<int> kmp(evil.size());
    for (auto j = 0, i = 1; i < kmp.size(); ++i) {
        if (evil[i] == evil[j])
            kmp[i] = ++j;
        else if (j > 0) {
            j = kmp[j - 1];
            --i;
        }
    }
    return dfs(s1, s2, evil, 0, 0, true, true, kmp);
}
};