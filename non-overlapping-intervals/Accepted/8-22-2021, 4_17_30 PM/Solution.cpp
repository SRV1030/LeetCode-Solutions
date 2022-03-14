// https://leetcode.com/problems/non-overlapping-intervals

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),
             [](vector<int>& v1,vector<int>& v2){
                if(v1[1]==v2[1])
                    return v1[0]<v2[0];
                return v1[1]<v2[1];
             }
        );
        int c=1,d=intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]>=d){
                c++;
                d=intervals[i][1];
                cout<<d<<" ";
            }
        }
        return intervals.size()-c;
    }
};