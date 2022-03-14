// https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort( points.begin(), points.end());
        int d= points[0][1],a=1,n=points.size();
        for(int i=1;i<n;i++){
            if(points[i][0]<=d) d=min(d,points[i][1]);
            else{
                a++;
                d=points[i][1];
            }
        }
        return a;
    }
};