class Solution {
public:
    int minBitFlips(int s, int g) {
        int c=0,xr=s^g;
        while(xr){
            xr&=(xr-1);
            c++;
        }
        return c;
    }
};