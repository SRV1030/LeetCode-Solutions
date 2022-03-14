// https://leetcode.com/problems/combination-sum-iii

class Solution {
public:vector<vector<int>> v;
    void comb(vector<int> &a,int k,int sum,int ind){
        if(sum==0 && k==0){
            v.push_back(a);
            return;
        }
        if(sum!=0 && k<=0) return;
        for(int i=ind;i<10;i++){
            a.push_back(i);
            comb(a,k-1,sum-i,i+1);
            a.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> a;
        comb(a,k,n,1);
        return v;
    }
};