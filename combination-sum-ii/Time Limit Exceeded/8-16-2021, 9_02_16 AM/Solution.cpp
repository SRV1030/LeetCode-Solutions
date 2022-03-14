// https://leetcode.com/problems/combination-sum-ii

class Solution {
public: set<vector<int>> v;
        
    void util(vector<int>&cands,vector<int>cmb,vector<int>vis,int i,int t){
        if(i==cands.size()){
            if(t==0)v.insert(cmb);
            return;
        }
        util(cands,cmb,vis,i+1,t);
        if(cands[i]<=t && !vis[i]){
            cmb.push_back(cands[i]);
            vis[i]=1;
            util(cands,cmb,vis,i+1,t-cands[i]);
        }
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>cmb;
        int i=0;
        sort(candidates.begin(),candidates.end());
        vector<int>vis(candidates.size());
        util(candidates,cmb,vis,i,target);
        vector<vector<int>> ans(v.begin(),v.end());
        return ans;
    }
};