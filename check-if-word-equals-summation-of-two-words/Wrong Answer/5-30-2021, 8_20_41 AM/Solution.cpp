// https://leetcode.com/problems/check-if-word-equals-summation-of-two-words

class Solution {
public:
    bool isSumEqual(string f, string s, string t) {
        int s1=0,s2=0,s3=0;
        for(auto i:f)s1+=(i-'a');
        for(auto i:s)s2+=(i-'a');
        for(auto i:t)s3+=(i-'a');
        return s3==(s1+s2);
        
        
    }
};