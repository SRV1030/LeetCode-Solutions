class Solution {
public:
    int findP(vector<int>&p,int i){
        return p[i]<0?i:p[i]=findP(p,p[i]);
    }
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        vector<int>p_both(n+1,-1);
        int u=0;
        for(int t=3;t>0;--t){
            auto p_one=p_both;
            auto &p=t==3?p_both:p_one;
            for(auto&e:edges){
                if(e[0]==t){
                    int i=findP(p,e[1]),j=findP(p,e[2]);
                    if(i!=j){
                        u++;
                        if(p[j]<p[i])swap(i,j);//one with smaller rank becomes parent. as rank is negative
                        p[i]+=p[j];
                        p[j]=i;
                    }
                }
            }
            if(t!=3 && p[findP(p,1)]!=-n) return -1;
        }
        return size(edges)-u;
    }
};