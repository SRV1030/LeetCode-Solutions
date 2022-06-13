class Solution {
public:
    int getS(int i,int j,vector<vector<int>>& tri){
        if(i<0 || j<0 || j>=tri[i].size()) return INT_MAX;
        return tri[i][j];
    }
    int minimumTotal(vector<vector<int>>& tri) {        
        for(int i=1;i<tri.size();i++)
            for(int j=0;j<tri[i].size();j++)
                tri[i][j]+=min(getS(i-1,j-1,tri),getS(i-1,j,tri));  
        return *min_element(tri[tri.size()-1].begin(),tri[tri.size()-1].end());
    }
};