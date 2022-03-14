// https://leetcode.com/problems/combination-sum

class Solution {
public: vector<vector<int>> v;
    void solve(vector<int>& candidates,int ind,int t,vector<int> ans){
        if(ind==candidates.size()){
            if(t==0)v.push_back(ans);
            return;
        }
        solve(candidates,ind+1,t,ans);
        if(candidates[ind]<=t){
            ans.push_back(candidates[ind]);
            solve(candidates,ind,t-candidates[ind],ans);
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int t) {
        vector<int> ans;
        solve(candidates,0,t,ans);
        return v;
    }
};