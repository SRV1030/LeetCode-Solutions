// https://leetcode.com/problems/stone-game-vi

class Solution {
public:
    int stoneGameVI(vector<int>& al, vector<int>& bo) {
        vector<vector<int>>v;
        for(int i=0;i<al.size();i++)v.push_back({al[i]+bo[i],al[i],bo[i]});
        sort(v.begin(),v.end(),greater<>());
        int a=0,b=0;
        for(int i=0;i<v.size();i++){
            if(i%2)b+=v[i][2];
            else a+=v[i][1];
        }
        return a==b?0:a>b?1:-1;
            
    }
};