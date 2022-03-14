// https://leetcode.com/problems/non-overlapping-intervals

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int c=0,d=intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<d){
                c++;
                if(intervals[i][1]<d)d=intervals[i][1];
            }
            else d=intervals[i][1];
        }
        return c;
    }
};