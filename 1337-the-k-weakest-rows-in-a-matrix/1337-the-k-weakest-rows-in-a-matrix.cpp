class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        set<pair<int,int>>st;
        vector<int> ans;
        for(int i=0;i<mat.size();i++){
            auto s=accumulate(mat[i].begin(),mat[i].end(),0);
            st.insert({s,i});
        }
        for(auto it=st.begin();k>0;++it,--k)ans.push_back(it->second);
        return ans;        
    }
};