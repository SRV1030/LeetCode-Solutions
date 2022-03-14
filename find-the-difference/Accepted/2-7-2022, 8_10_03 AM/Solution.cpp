// https://leetcode.com/problems/find-the-difference

class Solution {
public:
    char findTheDifference(string s, string t) {
        int c=0;
        for(int i:s) c-=i;
        for(int i:t) c+=i;
        return c;
    }
};