// https://leetcode.com/problems/combination-sum

class Solution {
public: vector<vector<int>> ans;
    void util(vector<int>& cd, int t,int i,vector<int> a){
        if(t<0)
            return;
        if(i==cd.size()){
            if(t==0)ans.push_back(a);
            return;
        }
        util(cd,t,i+1,a);
        if(cd[i]<=t){
            a.push_back(cd[i]);
            util(cd,t-cd[i],i,a);
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        util(candidates,target,0,{});
        return ans;
    }
};