// https://leetcode.com/problems/knight-probability-in-chessboard

class Solution {
public:
    double knightProbability(int n, int k, int r, int c) {
        vector<vector<double>>t1(n,vector<double>(n,0));         
        t1[r][c]=1;
        int dx[]={2,2,1,1,-2,-2,-1,-1};
        int dy[]={1,-1,2,-2,1,-1,2,-2};
        while(k--){
            vector<vector<double>>t2(n,vector<double>(n,0));
            for(int i=0;i<n;i++){                
                for(int j=0;j<n;j++){
                    for(int k=0;k<8;k++){
                        int x=i+dx[k],y=j+dy[k];
                        if(x>=0 && x<n && y>=0 && y<n){
                            t2[x][y]+=t1[x][y]/8.0;
                        }
                    }
                }
            }
            t1=t2;
            
        }
        double s=0;
        for(int i=0;i<n;i++)
            for(auto j:t1[i]) s+=j;
        
        return s;
        
        
    }
};