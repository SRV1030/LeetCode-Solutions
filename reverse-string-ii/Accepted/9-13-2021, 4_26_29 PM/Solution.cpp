// https://leetcode.com/problems/reverse-string-ii

class Solution {
public:
    string reverseStr(string s, int k) {
        for(int i=0;i<s.size();){
            if(i+k<s.size())reverse(s.begin()+i,s.begin()+i+k);
            else reverse(s.begin()+i,s.end());
            i+=2*k;
        }
        return s;
    }
};