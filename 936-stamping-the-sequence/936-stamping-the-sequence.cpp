class Solution {
public:
    bool canReplace(string st, string tg,int ind){
        for(int i=0;i<size(st);++i)
            if(tg[i+ind]!='?' && tg[i+ind]!=st[i]) return false;
        return true;
    }
    void replace(string &tg,int ns,int ind,int &c){
        for(int i=0;i<ns;++i)
            if(tg[i+ind]!='?'){
                tg[i+ind]='?';
                ++c;
            }
        return;
    }
    vector<int> movesToStamp(string st, string tg) {        
        int c=0,n=size(tg);
        vector<int>ans,vis(n);
        while(c<n){
            bool ch=false;
            for(int i=0;i<=n-size(st);++i){
                if(!vis[i]&&canReplace(st,tg,i)){
                    replace(tg,size(st),i,c);
                    vis[i]=1;
                    ans.insert(ans.begin(),i);
                    ch=true;
                    if(c==n) break;
                }                
            }
            if(!ch) return{};
        }
        return ans;
    }
};