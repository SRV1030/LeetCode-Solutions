// https://leetcode.com/problems/triangle

class Solution {
public:
    int minimumTotal(vector<vector<int>>& tri) {        
        for(int i=1;i<tri.size();i++){
            for(int j=0;j<tri[i].size();j++){
                if(i-1>=0 && j-1>=0 && j<tri[i-1].size())tri[i][j]+=min(tri[i-1][j-1],tri[i-1][j]);
                else if(i-1>=0  && j<tri[i-1].size()) tri[i][j]+=tri[i-1][j];
                else if(i-1>=0  && j-1>=0) tri[i][j]+= tri[i-1][j-1];                
            }
        }
                
        return *min_element(tri[tri.size()-1].begin(),tri[tri.size()-1].end());
    }
};