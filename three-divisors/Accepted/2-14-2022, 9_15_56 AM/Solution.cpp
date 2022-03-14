// https://leetcode.com/problems/three-divisors

class Solution {
public:
    bool isThree(int n) {
        int c=0;
        for(int i=1;i*i<=n;i++){
            if(n%i==0){
                c++;
                if(n/i!=i)c++;
            }
        }
        return c==3;
    }
};