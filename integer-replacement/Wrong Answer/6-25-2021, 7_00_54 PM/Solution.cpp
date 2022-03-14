// https://leetcode.com/problems/integer-replacement

class Solution {
public:
    int integerReplacement(int n) {
        if(n==1) return 0;
        if(n==2) return 1;
        int i=1,x,y=-1,j=0;
        while(true){
            x=pow(2,i);
            if(x==n) return i;
            if(x<n){
                j=i;
                 y=x;
            }
            else if(x>n) break;
            i++;
        }
        if(y==-1) return min(i+x-n,n);
        return min(i+x-n,j+n-y);
    }
};