// https://leetcode.com/problems/queries-on-number-of-points-inside-a-circle

class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
       vector<int> ans;
        for(auto& q:queries){
            int c=0;
            for(auto& p:points){
                int d=(p[0]-q[0])*(p[0]-q[0])+(p[1]-q[1])*(p[1]-q[1]);
                int r=q[2]*q[2];
                if(d<=r) c++;
            }
            ans.emplace_back(c);
        }
        return ans;
    }
};