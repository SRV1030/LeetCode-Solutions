// https://leetcode.com/problems/interval-list-intersections

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& f, vector<vector<int>>& s) {
        int i=0,j=0,l1=f.size(),l2=s.size();
        vector<vector<int>> v;
        while(i<l1 && j<l2){
            int st=max(f[i][0],s[j][0]),e=min(f[i][1],s[j][1]);
            if(st<=e)v.push_back({st,e});
            f[i][1]>s[j][1]?j++:i++;  
        }
        return v;
    }
};