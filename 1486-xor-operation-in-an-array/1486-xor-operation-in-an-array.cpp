class Solution {
public:
    int xorOperation(int n, int start) {
        int xr=0;
        for(int i=0;i<n;++i)xr^=(2*i+start);
        return xr;
    }
};