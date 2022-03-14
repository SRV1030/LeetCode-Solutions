// https://leetcode.com/problems/find-the-highest-altitude

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int cur=0,mx=0;
        gain.insert(gain.begin(),0);
        for(auto&i:gain)mx=max(mx,cur+i),cur=cur+i;
        return mx;
    }
};