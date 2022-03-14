// https://leetcode.com/problems/permutations

class Solution {
    
public:vector<vector<int>> v;
    void util(vector<int>& n,int l,int h){
        if(l==h)v.push_back(n);
        else{
            for(int i=l;i<=h;i++){
                swap(n[l],n[i]);
                util(n,l+1,h);
                swap(n[l],n[i]);
            }
        }
    }
    vector<vector<int>> permute(vector<int>& n) {
        v.clear();
        util(n,0,n.size()-1);
        return v;       
        
    }
};