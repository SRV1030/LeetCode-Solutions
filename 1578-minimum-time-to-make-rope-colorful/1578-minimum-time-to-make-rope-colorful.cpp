class Solution {
public:
    int minCost(string s, vector<int>& nt) {
        int mx=nt[0],res=nt[0];
        for(int i=1;i<size(nt);++i){
            if(s[i-1]!=s[i]){
                res-=mx;
                mx=0;
            }
            res+=nt[i];
            mx=max(mx,nt[i]);
        }
        return res-mx;
    }
};