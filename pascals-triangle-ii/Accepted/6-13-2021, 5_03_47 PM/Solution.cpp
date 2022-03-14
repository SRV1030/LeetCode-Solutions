// https://leetcode.com/problems/pascals-triangle-ii

class Solution {
public:
    vector<int> getRow(int n) {
         if(n==0) return{1};
        else if(n==1) return{1,1};
        vector<vector<int>>v;
        v={{1},{1,1}};
        for(int i=2;i<=n;i++){
            vector<int> t;
            t.push_back(1);
            for(int j=1;j<i;j++)t.push_back(v[i-1][j-1]+v[i-1][j]);
            t.push_back(1);
            v.push_back(t);
        }
        return v[n];
    }
    
};