// https://leetcode.com/problems/reverse-integer

class Solution {
public:
    int reverse(int x) {
        if(x==INT_MIN || x==INT_MAX) return 0;
        int res=0,s=x<0;
        while(x){
            int d=fmod(x,10);
            x/=10;   
            if(res<INT_MIN/10 || (res==INT_MIN/10 && res<=INT_MIN%10)) return 0;
            if(res>INT_MAX/10 || (res==INT_MAX/10 && res>=INT_MAX%10)) return 0;
            res=res*10+d;
        }
        return res;
    }
};