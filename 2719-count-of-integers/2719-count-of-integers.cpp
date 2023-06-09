int dp[23][9 * 22][2], mod = 1000000007;
class Solution {
public:
int dfs(int i, int sum, int min_sum, int max_sum, const string &num, bool lim, bool equal) {
    if (i == 0)
        memset(dp, -1, (num.size()) * sizeof(dp[0]));
    if (i == num.size() || sum > max_sum)
        return sum >= min_sum && sum <= max_sum && (equal || !lim);
    if (dp[i][sum][lim] == -1)
        for (char n = '0'; n <= (lim ? num[i] : '9'); ++n)
            dp[i][sum][lim] = (max(0, dp[i][sum][lim]) + 
                dfs(i + 1, sum + n - '0', min_sum, max_sum, num, lim && n == num[i], equal)) % 1000000007;
    return dp[i][sum][lim];
}
int count(string num1, string num2, int min_sum, int max_sum) {
    return (mod + dfs(0, 0, min_sum, max_sum, num2, true, true)
                - dfs(0, 0, min_sum, max_sum, num1, true, false)) % mod;
}
};