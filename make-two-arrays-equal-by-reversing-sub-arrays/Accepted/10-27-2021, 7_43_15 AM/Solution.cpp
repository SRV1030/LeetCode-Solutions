// https://leetcode.com/problems/make-two-arrays-equal-by-reversing-sub-arrays

class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int,int>mp;
        for(int i=0;i<target.size();i++){
            mp[target[i]]++;
            mp[arr[i]]--;
        }
        for(auto&[k,v]:mp)
            if(v) return false;
        return true;
    }
};