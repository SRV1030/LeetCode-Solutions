// https://leetcode.com/problems/diagonal-traverse

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        map<int ,vector<int>>mp;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                mp[i+j].push_back(mat[i][j]);
            }
        }
        vector<int>ans;
        for(auto i:mp){
            if(i.first%2==0){
                for(int j=i.second.size()-1;j>=0;j--)ans.push_back(i.second[j]);
            }
            else ans.insert(ans.end(),i.second.begin(),i.second.end());
        }
        return ans;
    }
};