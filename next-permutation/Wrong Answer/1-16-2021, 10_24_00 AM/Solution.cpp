// https://leetcode.com/problems/next-permutation

class Solution {
public:
    void nextPermutation(vector<int> &v) {
        if(v.size()==1) return;
        int i=v.size()-1;
        for(i;i>=1;i--){
            if(v[i]>v[i-1]){
                int j=i;
                while(v[j]<=v[i-1]) j=(j+1)%v.size();
                swap(v[j],v[i-1]);
                reverse(v.begin()+i,v.end());
                return;
            }
        }
        reverse(v.begin(),v.end());
                return;
    }
        
};