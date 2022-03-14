// https://leetcode.com/problems/rectangle-overlap

class Solution {
public:
    bool isRectangleOverlap(vector<int>& r1, vector<int>& r2) {
        return min(r1[1],r2[1])<max(r1[0],r2[0]) && 
            min(r1[0],r2[0])<max(r1[1],r2[1]);
        
    }
};