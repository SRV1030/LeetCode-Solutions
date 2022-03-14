// https://leetcode.com/problems/reverse-integer

class Solution {
public:
    int reverse(int x) {
        int res=0,s=x<0;        
        while(x){
            int d=fmod(x,10);
            x/=10;   
            if(s)
                if(x>INT_MAX/10 || (x==INT_MAX/10 && d>=INT_MAX%10)) return 0;
            else if(x<INT_MIN/10 || (x==INT_MIN/10 && d<=INT_MIN%10)) return 0;
            res=res*10+d;
            
        }
        return res;
    }
};