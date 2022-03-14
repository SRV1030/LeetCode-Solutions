// https://leetcode.com/problems/minimum-operations-to-make-a-uni-value-grid

class Solution {
public:
    int minOperations(vector<vector<int>>& g, int x) {
        vector<int>r;
        int md=g[0][0]%x,mn1=0;
        for(auto&i:g)
            for(auto&j:i){
                r.push_back(j);
                if(j%x!=md) return -1;
            }
        sort(r.begin(),r.end());
        int n=r.size(),median1=r[n/2];
        for(auto&i:r)mn1+=abs(i-median1)/x;
        if(n%2==0){
            int median2=r[(n-1)/2],mn2=0;
            for(auto&i:r)mn2+=abs(i-median2)/x;
            if(mn2<mn1)mn1=mn2;
        }
        return mn1;
    }
};