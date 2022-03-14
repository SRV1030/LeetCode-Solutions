// https://leetcode.com/problems/check-if-every-row-and-column-contains-all-numbers

class Solution {
public:
    bool checkValid(vector<vector<int>>& mat) {
        int n=mat.size();
        for(int i=0;i<n;i++){
            vector<int>v(n);            
            for(int j=0;j<n;j++) v[mat[i][j]-1]++;
            for(auto& i:v)if(i!=1)return false;
        }
        for(int i=0;i<n;i++){
            vector<int>v(n);
            for(int j=0;j<n;j++) v[mat[j][i]-1]++;
            for(auto& i:v)if(i!=1)return false;
        }
        return true;
    }
};