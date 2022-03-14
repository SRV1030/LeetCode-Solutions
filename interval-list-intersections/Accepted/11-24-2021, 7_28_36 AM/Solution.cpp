// https://leetcode.com/problems/interval-list-intersections

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& f, vector<vector<int>>& s) {
        int i=0,j=0,nf=f.size(),ns=s.size();
        vector<vector<int>> v;
        while(i<nf && j<ns){
            int st=max(f[i][0],s[j][0]),e=min(f[i][1],s[j][1]);
            if(st<=e)v.push_back({st,e});
            f[i][1]==e?i++:j++;
        }
        return v;
    }
};