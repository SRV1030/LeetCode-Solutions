// https://leetcode.com/problems/count-nice-pairs-in-an-array

// let's say
// a = nums[i] and b = nums[j]
// ra = rev(a), rb = rev(b)
// if a - ra == k and b - rb == k
// that means a - ra == b - rb i.e a + rb == b + ra

class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        unordered_map<long, int> cnt;
        long long res = 0, mod = 1e9 + 7;
        for (long n : nums) {
            long t = 0, b = n;
            while (b) {
                t *= 10;
                t += b % 10;
                b /= 10;
            }
            long d = n - t ;
            res += cnt[d];
            cnt[d]++;
        }
        return res % mod;
    }
};