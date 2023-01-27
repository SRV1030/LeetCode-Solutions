class Solution {
public:
    int alternateDigitSum(int n) {
        int s=0,i=1;        
        while(n){
            i=-i;
            s+=(i*(n%10));
            n/=10;
        }
        return s*i;
    }
};