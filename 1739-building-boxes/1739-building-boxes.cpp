class Solution {
public:
    int minimumBoxes(int n) {
        int bd=0,exd=0;
        while(n-(bd+1)*(bd+2)/2>0){            
            bd++;   
            n-=(bd)*(bd+1)/2;             
        }
        while(n>0)
            n-=++exd;
        return (bd)*(bd+1)/2+exd;
    }
};