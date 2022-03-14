// https://leetcode.com/problems/triangle

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int x=0;
        for(auto i: triangle){
            x+=*min_element(i.begin(),i.end());
        }
        return x;
    }
};