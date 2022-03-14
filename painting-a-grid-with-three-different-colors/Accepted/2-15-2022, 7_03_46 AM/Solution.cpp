// https://leetcode.com/problems/painting-a-grid-with-three-different-colors

class Solution {
public:
    int md=1000000007;
    vector<string> st;
    int dp[50][1001];
    void fill(int m,char prev,string s){
        if(m==0)st.push_back(s);
        else{
            string t="RGB";
            for(auto&i:t){
                if(i!=prev) fill(m-1,i,s+i);
            }           
        }
        
    }
    int dfs(vector<vector<int>> &gr,int i,int n){
        if(!n) return 1;
        if(dp[i][n]!=-1) return dp[i][n];
        int ans=0;
        for(auto&j:gr[i]) ans=(ans%md+dfs(gr,j,n-1)%md)%md;
        return dp[i][n]=ans%md;
    }
    int colorTheGrid(int m, int n) {
        fill(m,'#',"");
        memset(dp,-1,sizeof(dp));
        int sz=st.size();
        vector<vector<int>>gr(sz);
        for(int i=0;i<sz;i++){
            for(int j=i+1;j<sz;j++){                
                bool f=false;
                for(int k=0;k<m;k++){
                    if(st[i][k]==st[j][k]){
                        f=true;
                        break;
                    }
                }
                if(!f){
                    gr[i].push_back(j);
                    gr[j].push_back(i);
                }
            }
        }
        int ans=0;
        for(int i=0;i<sz;i++) ans=(ans%md+dfs(gr,i,n-1)%md)%md;
        return ans;
    }
};