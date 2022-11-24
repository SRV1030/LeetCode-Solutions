class Solution {
public: int m,n,s;
    int x[4]={1,-1,0,0};
    int y[4]={0,0,1,-1};
    bool dfs(vector<vector<char>>& b,string w,int i,int j,int ind){
        if(b[i][j]!=w[ind]) return false;        
        if(ind==s-1) return true;
        char c=b[i][j];
        b[i][j]='$';
        bool f=false;
        for(int d=0;d<4;d++){
            int dx=i+x[d],dy=j+y[d];
            if(dx<0 || dx>=m || dy<0 || dy>=n || b[dx][dy]=='$') continue;
            f=f||dfs(b,w,dx,dy,ind+1);
        }
       b[i][j]=c;
       return f;        
    }
    bool exist(vector<vector<char>>& b, string w) {
        m=b.size();
        n=b[0].size();
        s=w.length();
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(b[i][j]==w[0])
                    if(dfs(b,w,i,j,0)) return true;
        return false;
    }
};