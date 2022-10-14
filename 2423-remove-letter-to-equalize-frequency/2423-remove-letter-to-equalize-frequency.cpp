class Solution {
public:
    bool equalFrequency(string word) {
        vector<int>f(26);
        for(auto&i:word)++f[i-'a'];
        int mnf=INT_MAX,mxf=0,cmx=0,cmn=0;
        for(int i=0;i<26;++i){
            if(f[i]){
                mnf=min(mnf,f[i]);
                mxf=max(mxf,f[i]);
            }
        }
        for(int i=0;i<26;++i){
            if(f[i]){
                if(f[i]==mxf)++cmx;
                else if(f[i]==mnf)++cmn;
                else return false;
            }
        }
        if(mxf==mnf) return cmx==1 || mxf==1;
        if(cmn==1 && mnf==1) return true;
        if(mxf!=mnf+1 || cmx!=1) return false;
        return true;
        
    }
};