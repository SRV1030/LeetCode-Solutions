// https://leetcode.com/problems/max-increase-to-keep-city-skyline

class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& g) {
        int n=g.size(),s=0;
        vector<int>y(n,0),x(n,0);
        for(int i=0;i<n;i++){           
            for(int j=0;j<n;j++){
               y[i]=max(y[i],g[j][i]); 
               x[i]=max(x[i],g[i][j]);
            } 
        }
         for(int i=0;i<n;i++){
             for(int j=0;j<n;j++){
                 s+=min(x[i],y[j])-g[i][j];
             }
         }
        return s;        
    }
};