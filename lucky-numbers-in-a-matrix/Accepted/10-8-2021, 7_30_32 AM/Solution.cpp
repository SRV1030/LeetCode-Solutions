// https://leetcode.com/problems/lucky-numbers-in-a-matrix

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& mat) {
        int r=mat.size(),c=mat[0].size();
        vector<int>ans;
        unordered_set<int>st;
        for(int i=0;i<r;i++)st.insert(*min_element(mat[i].begin(),mat[i].end()));
        int ind=0;
        for(int i=0;i<c;i++){
            int mx=INT_MIN;
            for(int j=0;j<r;j++) if(mat[j][i]>mx)mx=mat[j][i];
            if(st.count(mx)) ans.push_back(mx);
        }
        return ans;
    }
};