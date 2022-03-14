// https://leetcode.com/problems/combination-sum

class Solution {
public:
    int n;
    vector<vector<int>>v;
    void comb(vector<int>&cand,int i,int t,vector<int>ans){
        if(i==n){
            if(t==0) v.push_back(ans);
            return;
        }
        comb(cand,i+1,t,ans);
        if(cand[i]<=t){
            ans.push_back(cand[i]);
            comb(cand,i,t-cand[i],ans);
        }
    }
    vector<vector<int>> combinationSum(vector<int>& cand, int t) {
        n=cand.size();
        vector<int>ans;
        comb(cand,0,t,ans);
        return v;
    }
};
