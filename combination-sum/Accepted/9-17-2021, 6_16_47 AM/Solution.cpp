// https://leetcode.com/problems/combination-sum

class Solution {
public: vector<vector<int>> ans;
    void util(vector<int>&c,int t,int i,vector<int>a){
        if(t<0)return;
        if(i==c.size()) {            
            if(t==0) ans.push_back(a);
            return;
        }
        util(c,t,i+1,a);
        if(c[i]<=t){
            a.push_back(c[i]);
            util(c,t-c[i],i,a);
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        util(candidates,target,0,{});
        return ans;
    }
};