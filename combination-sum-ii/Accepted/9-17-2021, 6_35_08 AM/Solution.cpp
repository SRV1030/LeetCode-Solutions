// https://leetcode.com/problems/combination-sum-ii

class Solution {
public:
    vector<vector<int>> v;
    void util(vector<int>& c,int t,int ind,vector<int>a){
        if(t<0) return;
        if(t==0)v.push_back(a);
        for(int i=ind;i<c.size();i++){
            if(i!=ind && c[i]==c[i-1])continue;
            if(c[i]>t) break;
            a.push_back(c[i]);
            util(c,t-c[i],i+1,a);
            a.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        util(candidates, target,0,{});
        return v;
    }
};