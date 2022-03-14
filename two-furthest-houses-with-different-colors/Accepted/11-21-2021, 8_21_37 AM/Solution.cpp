// https://leetcode.com/problems/two-furthest-houses-with-different-colors

class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int l1=0,l2=0,r1=colors.size()-1,r2=colors.size()-1;
        while(l1<=r1 && colors[l1]==colors[r1])l1++;
        while(l2<=r2 && colors[l2]==colors[r2])r2--;
        return max(r1-l1,r2-l2);
    }
};