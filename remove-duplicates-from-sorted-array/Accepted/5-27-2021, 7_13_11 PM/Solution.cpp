// https://leetcode.com/problems/remove-duplicates-from-sorted-array

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int>s(nums.begin(),nums.end());
        vector<int>num(s.begin(),s.end());
        nums=num;
        return s.size();
    }
};