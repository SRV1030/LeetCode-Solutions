// https://leetcode.com/problems/check-if-all-as-appears-before-all-bs

class Solution {
public:
    bool checkString(string s) {
        bool f=0;
        for(auto&i:s){
            if(f && i=='a') return false;
            if(i=='b') f=1;
        }
        return true;
    }
};