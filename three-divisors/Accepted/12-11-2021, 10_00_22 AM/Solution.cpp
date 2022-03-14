// https://leetcode.com/problems/three-divisors

class Solution {
public:
    bool isThree(int n) {
        if(n==1) return false;
        int dc=0;
        for(int i=1;i*i<=n;i++){
            if(n%i==0){
                dc++;
                if(n/i!=i)dc++;
            }
        }
        return dc==3;
    }
};