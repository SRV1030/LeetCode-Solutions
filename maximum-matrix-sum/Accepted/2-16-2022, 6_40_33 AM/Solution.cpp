// https://leetcode.com/problems/maximum-matrix-sum

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int mn=INT_MAX,n=0;
        long long s=0;
        for(auto&i:matrix)
            for(auto&j:i){
                if(j<0){
                    n++;
                    j=abs(j);
                }
                s+=j;
                if(j<mn)mn=j;
            }
        if(n&1) return s-2*mn;
        return s;
    }
};