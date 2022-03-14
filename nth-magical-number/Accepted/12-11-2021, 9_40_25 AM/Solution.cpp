// https://leetcode.com/problems/nth-magical-number

class Solution {
public:
    int MOD=1e9+7;
    int gcd(int x, int y) {
        if (x == 0) return y;
        return gcd(y % x, x);
    }    
    int lcm(int a,int b){
        return (a/gcd(a,b))*b;
    }
    int nthMagicalNumber(int N, int A, int B) {
        int MOD = 1e9 + 7;
        int L = A / gcd(A, B) * B;

        long lo = 0;
        long hi = (long) N * min(A, B);
        while (lo < hi) {
            long mi = lo + (hi - lo) / 2;
            // If there are not enough magic numbers below mi...
            if (mi / A + mi / B - mi / L < N)
                lo = mi + 1;
            else
                hi = mi;
        }

        return (int) (lo % MOD);
        
    }
};