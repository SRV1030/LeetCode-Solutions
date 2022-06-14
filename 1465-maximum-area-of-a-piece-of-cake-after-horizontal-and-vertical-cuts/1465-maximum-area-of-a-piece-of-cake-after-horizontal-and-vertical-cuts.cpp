class Solution {
public:
    int md=1e9+7;
    int maxArea(int h, int w, vector<int>& hcx, vector<int>& vcx) {        
        sort(begin(hcx),end(hcx));
        sort(begin(vcx),end(vcx));
        int hc=hcx[0],vc=vcx[0];
        for(int i=1;i<size(hcx);++i)hc=max(hc,hcx[i]-hcx[i-1]);
        hc=max(hc,h-hcx.back());
        for(int i=1;i<size(vcx);++i)vc=max(vc,vcx[i]-vcx[i-1]);
        vc=max(vc,w-vcx.back());
        return ((long)(hc%md)*(vc%md))%md;
    }
};