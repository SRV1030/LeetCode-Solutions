// https://leetcode.com/problems/reverse-integer

class Solution {
public:
    int reverse(int x) {
        int res=0,s=x<0;
        x=abs(x);        
        while(x){
            res=res*10+(x%10);
            x/=10;
        }
        return s?-res:res;
    }
};