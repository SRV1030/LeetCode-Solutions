// https://leetcode.com/problems/monotone-increasing-digits

class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string s=to_string(n);
        int x=s.length()-1,j=x;
        while(j>0 && s[j-1]<=s[j])j--;
        if(j<=0) return n;
        j--;
        while(j<=x)s[j++]='0';
        n=stoi(s);
        return n-1;
        
    }
};