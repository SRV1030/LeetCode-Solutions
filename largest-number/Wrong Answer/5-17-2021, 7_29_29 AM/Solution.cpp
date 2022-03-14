// https://leetcode.com/problems/largest-number

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string>v;
        for(auto i:nums)v.push_back(to_string(i));
        sort(v.begin(),v.end());
        string s;
        for(int j=v.size()-1;j>=0;j--)s+=v[j];
        return s;
    }
};