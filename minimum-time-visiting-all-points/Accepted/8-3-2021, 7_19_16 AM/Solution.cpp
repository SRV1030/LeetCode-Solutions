// https://leetcode.com/problems/minimum-time-visiting-all-points

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int mx=0;
        for(int i=0;i<points.size()-1;i++)
            mx+=max(abs(points[i+1][0]-points[i][0]),abs(points[i+1][1]-points[i][1]));
        return mx;
    }
};