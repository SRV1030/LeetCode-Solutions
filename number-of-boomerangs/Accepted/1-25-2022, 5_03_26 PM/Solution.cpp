// https://leetcode.com/problems/number-of-boomerangs

class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        unordered_map<int,int>mp;
        int ans=0;
        for(int i=0;i<points.size();i++){
            for(int j=0;j<points.size();j++){
                if(i==j) continue;
                int dist=(points[i][0] - points[j][0])*(points[i][0] - points[j][0]) + (points[i][1] - points[j][1])*(points[i][1] - points[j][1]);
                mp[dist]++;
            }            
            for(auto&[k,v]:mp)ans+=v*(v-1);
            mp.clear();
        }
        return ans;
    }
};