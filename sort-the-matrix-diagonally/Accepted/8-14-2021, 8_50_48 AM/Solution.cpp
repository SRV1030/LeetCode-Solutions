// https://leetcode.com/problems/sort-the-matrix-diagonally

class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& m1) {
        vector<vector<int>> mat=m1;
        unordered_map<int,vector<int>>mp;
        int n=mat.size(),m=mat[0].size();
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                mp[j-i].push_back(mat[i][j]);            
        for(auto i:mp){
            sort(i.second.begin(),i.second.end());
            mp[i.first]=i.second;
        }  
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++){
                mat[i][j]=mp[j-i][0];
                mp[j-i].erase(mp[j-i].begin());
            }
         return mat;      
    }
};