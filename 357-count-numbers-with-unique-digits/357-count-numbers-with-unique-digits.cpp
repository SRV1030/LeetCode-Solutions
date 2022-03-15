class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n==0) return 1;
        int a=9,s=9,res=10;
        n--;
        while(n-- && a>0){
            s*=a;
            res+=s;
            a--;
        }
        return res;
    }
};