class Solution {
public:
    int numTeams(vector<int>& r) {
        int n=size(r);
        int ans=0;
        for(int i=1;i<n-1;++i){
            int lmn=0,lmx=0,rmn=0,rmx=0;
            for(int j=i-1;j>=0;--j)
                if(r[j]>r[i])++lmx;
                else ++lmn;
            for(int j=i+1;j<n;++j)
                if(r[j]>r[i])++rmx;
                else ++rmn;
            ans+=(lmx*rmn+lmn*rmx);
        }
        return ans;
    }
};