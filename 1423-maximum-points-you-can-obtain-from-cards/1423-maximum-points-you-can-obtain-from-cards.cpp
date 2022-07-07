class Solution {
public:
    int maxScore(vector<int>& cp, int k) {
        int s=0,cs=0;
        for(int i=0;i<k;++i)s+=cp[i];
        cs=s;
        for(int i=k-1;i>=0;--i){
            cs-=cp[i];
            cs+=cp[size(cp)-k+i];
            if(cs>s)s=cs;
        }
        return s;
    }
};