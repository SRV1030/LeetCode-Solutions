// https://leetcode.com/problems/length-of-last-word

class Solution {
public:
    int lengthOfLastWord(string s) {
        int j=s.size()-1,i=0;
        while(s[j]==' ')j--;
        i=j;
        while(s[i]!=' ')i--;
        i++;
        return j-i+1;
    }
};