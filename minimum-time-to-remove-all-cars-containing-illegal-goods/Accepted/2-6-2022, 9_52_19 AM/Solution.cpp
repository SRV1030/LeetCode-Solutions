// https://leetcode.com/problems/minimum-time-to-remove-all-cars-containing-illegal-goods



// Intuition: after removing "dirty" cars, we will have one or more consecutive "clean" cars.

// C++
class Solution {
public:
    int minimumTime(string s) {
    int sz = s.size(), res = sz;
    vector<int> vl(sz + 1), vr(sz + 1);
    for (int i = 0; i < sz; ++i) {
        vl[i + 1] = min(vl[i] + 2 * (s[i] == '1'), i + 1);
        vr[sz - i - 1] = min(vr[sz - i] + 2 * (s[sz - i - 1] == '1'), i + 1);
    }
    for (int i = 0, j = 0; i < sz; ++i) {
        if (s[i] == '1')
            j = i + 1;
        res = min(res, vl[j] + vr[i]);
    }
    return res;
}
};