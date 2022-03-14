// https://leetcode.com/problems/reverse-integer

class Solution {
public:
    int reverse(int x) {
        int res=0,mx=INT_MAX/10,mn=INT_MIN/10;
        while(x){
            int d=fmod(x,10);
            x/=10;   
            if(res>mx || (res==mx && d>=7)) return 0;
            if(res<mn || (res==mn && d<=8)) return 0;
            res=res*10+d;
        }
        return res;
    }
};