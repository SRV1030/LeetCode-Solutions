// https://leetcode.com/problems/minimize-maximum-pair-sum-in-array

class Solution {
public:
    int minPairSum(vector<int>& a) {
        int mn=*min_element(a.begin(), a.end()); 
        int mx=*max_element(a.begin(), a.end()); 
        return mx+mn;
        
    }
};