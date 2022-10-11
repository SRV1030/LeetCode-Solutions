class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        vector<int>f(n);
        int mx=-1,mi=-1,pv=0;
        for(auto&i:logs){
            f[i[0]]=max(f[i[0]],i[1]-pv);
            pv=i[1];
            if(f[i[0]]>=mx){
                if(f[i[0]]==mx)mi=min(i[0],mi);
                else mi=i[0];
                mx=f[i[0]];                
            }
        }
        return mi;
    }
};