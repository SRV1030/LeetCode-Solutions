// https://leetcode.com/problems/toeplitz-matrix

// class Solution {
// public:
//     bool isToeplitzMatrix(vector<vector<int>>& mat) {
//         unordered_map<int,int>mp;
//         for(int i=0;i<mat.size();i++)
//             for(int j=0;j<mat[0].size();j++){
//                 int k=i-j;
//                 if(mp.count(k)){
//                     if(mp[k]!=mat[i][j]) return false;
//                 }
//                 else mp[k]=mat[i][j];
//             }
//         return true;
            
//     }
// };

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& mat) {
        for(int i=1;i<mat.size();i++)
            for(int j=1;j<mat[0].size();j++){
                if(mat[i][j]!=mat[i-1][j-1]) return false;
            }
        return true;
    }
};