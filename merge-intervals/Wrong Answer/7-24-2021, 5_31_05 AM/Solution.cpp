// https://leetcode.com/problems/merge-intervals

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size()==1) return intervals;
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> v;
        v.push_back(intervals[0]);
        int ind=0;
        for(int i=1;i<intervals.size();i++){
            if(v[ind][1]>=intervals[i][0])v[ind][1]=intervals[i][1];
            else {
                v.push_back(intervals[i]);
                ind++;
            }
        }
        return v;
    }
};