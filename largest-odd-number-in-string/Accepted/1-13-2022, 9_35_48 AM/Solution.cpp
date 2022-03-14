// https://leetcode.com/problems/largest-odd-number-in-string

class Solution {
public:
    string largestOddNumber(string num) {
        int i=num.size()-1;
        for(;i>=0;i--)
            if((num[i]-'0')%2) break;
        return i<0?"":num.substr(0,i+1);
    }
};