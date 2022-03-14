// https://leetcode.com/problems/sum-of-unique-elements

class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        vector<int>f(101);
        int c=0;
        for(auto&i:nums) c+=++f[i]==1?i:f[i]==2?-i:0;
        return c;
    }
};