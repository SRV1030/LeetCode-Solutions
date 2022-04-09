class Solution {
public:
    unordered_map<int,vector<int>>mp;
    vector<int>ans;    
    unordered_set<int>st;
    void dfs(int k){
        st.insert(k);
        ans.emplace_back(k);
        for(auto&i:mp[k]){
            if(!st.count(i)) dfs(i);
        }
    }
    vector<int> restoreArray(vector<vector<int>>& adj) {
        for(auto&i:adj){
            mp[i[0]].push_back(i[1]);
            mp[i[1]].push_back(i[0]);
        }
        for(auto&[k,v]:mp){
            if(v.size()==1){
                dfs(k);
                return ans;
            }            
        }
        return {};
    }
};