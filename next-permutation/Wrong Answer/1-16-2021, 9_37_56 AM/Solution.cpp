// https://leetcode.com/problems/next-permutation

class Solution {
public:
    void nextPermutation(vector<int> &v) {
        if(v.size()==1) return;
        for(int i=v.size()-1;i>=1;i--){
            if(v[i]>v[i-1]){
                swap(v[i],v[i-1]);
                return;
            }
        }
        sort(v.begin(),v.end());
        return;
        
    }
};