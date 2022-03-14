// https://leetcode.com/problems/knight-probability-in-chessboard

class Solution {
public:
    double knightProbability(int n, int k, int r, int c) {
        vector<vector<double>>v1(n,vector<double>(n,0));
        v1[r][c]=1;
        int dx[]={2,2,1,1,-1,-1,-2,-2};
        int dy[]={1,-1,2,-2,2,-2,1,-1};
        while(k--){
            vector<vector<double>>v2(n,vector<double>(n,0));
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    for(int d=0;d<8;d++){
                        int x=i+dx[d],y=j+dy[d];
                        if(x>=0 && x<n && y>=0 && y<n){
                            v2[x][y]+=v1[i][j]/8.0;
                        }
                    }
                }
            }
            v1=v2;
        }
        double p=0;
        for(auto i:v1)
            for(auto j:i)p+=j;
        return p;
    }
};