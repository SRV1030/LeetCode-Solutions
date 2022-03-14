// https://leetcode.com/problems/count-array-pairs-divisible-by-k

class Solution {
public:
    long long countPairs(vector<int>& nums, int k) {
    long long res = 0;
    unordered_map<int, int> gcds;
    for (int n : nums) {
        long long gcd_i = gcd(n, k);
        for (auto &[gcd_j, cnt] : gcds)
            if (gcd_i * gcd_j % k == 0)
                res += cnt;
        ++gcds[gcd_i];
    }
    return res;
}
};