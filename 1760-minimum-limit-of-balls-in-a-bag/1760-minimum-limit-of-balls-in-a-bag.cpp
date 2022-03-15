class Solution {
public:
    int minimumSize(vector<int>& A, int k) {
        int left = 1, right = 1e9;
        while (left < right) {
            int mid = (left + right) / 2, count = 0;
            for (int a : A)
                count += (a - 1) / mid;
            if (count > k)
                left = mid + 1;
            else
                right = mid;
        }
        return left;
    }
};
// https://leetcode.com/problems/minimum-limit-of-balls-in-a-bag/discuss/1064548/JavaC%2B%2BPython-Binary-Search