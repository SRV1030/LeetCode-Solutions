// https://leetcode.com/problems/combination-sum-ii

class Solution {
public: vector<vector<int>> v;
        
    void util(vector<int>&cands,vector<int>cmb,int ind,int t){
        if(t==0){
            v.push_back(cmb);
            return;
        } 
        for(int i=ind;i<cands.size();i++){
            if(t-cands[i]<0) break;
            if(i>ind && cands[i-1]==cands[i]) continue;
            cmb.push_back(cands[i]);
            util(cands,cmb,i+1,t-cands[i]);
            cmb.pop_back();
        }
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        util(candidates,{},0,target);
        return v;
    }
};