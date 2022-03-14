// https://leetcode.com/problems/watering-plants-ii

class Solution {
public:
    int minimumRefill(vector<int>& A, int ca, int cb) {
        int N = A.size(), i = 0, j = N - 1, ans = 0, a = ca, b = cb; // i/j is the position of Alice/Bob. a/b is the water of Alice/Bob
        while (i <= j) {
            if (i == j) { // If Alice and Bob are at the same spot
                if (a >= b) ans += a < A[i++];
                else ans += b < A[j--];
            } else {
                if (a < A[i]) a = ca, ++ans;
                a -= A[i++];
                if (b < A[j]) b = cb, ++ans;
                b -= A[j--];
            }
        }
        return ans;
    }
};