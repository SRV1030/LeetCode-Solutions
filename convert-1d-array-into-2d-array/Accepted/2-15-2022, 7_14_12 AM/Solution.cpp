// https://leetcode.com/problems/convert-1d-array-into-2d-array

class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& og, int m, int n) {
        vector<vector<int>> ans;
        int sz=og.size();
        if(sz!=m*n) return ans;
        int i=0;
        while(m-- && i<sz){
            vector<int>t;
            for(int j=0;j<n;j++)t.emplace_back(og[i++]);
            ans.emplace_back(t);            
        }
        return ans;
    }
};