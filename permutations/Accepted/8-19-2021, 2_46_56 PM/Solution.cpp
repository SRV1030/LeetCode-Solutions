// https://leetcode.com/problems/permutations

class Solution {
    
public:vector<vector<int>> v;
    void util(vector<int> a,int l,int h){
        if(l==h)v.push_back(a);
        else{
            for(int i=l;i<=h;i++){
                swap(a[l],a[i]);
                util(a,l+1,h);
                swap(a[l],a[i]);
            }
        }
    }
    vector<vector<int>> permute(vector<int>& n) {
        v.clear();
        util(n,0,n.size()-1);
        return v;       
        
    }
};