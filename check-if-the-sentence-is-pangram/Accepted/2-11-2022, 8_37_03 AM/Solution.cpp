// https://leetcode.com/problems/check-if-the-sentence-is-pangram

class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int>v(26);
        for(auto& i:sentence)v[i-'a']++;
        for(auto&i:v)if(!i) return false;
        return true;
    }
};