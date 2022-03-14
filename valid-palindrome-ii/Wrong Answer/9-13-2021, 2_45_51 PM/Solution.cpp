// https://leetcode.com/problems/valid-palindrome-ii

class Solution {
public:
    bool validPalindrome(string s) {
        int i=0,j=s.size();
        bool f=0;
        while(i<j){
            if(s[i]!=s[j]){
                if(f) return false;
                if(i+1==j) return true;
                if(i+1<j && s[i+1]==s[j])i++;
                else if(i<j-1 && s[i]==s[j-1])j--;
                else return false;
            }
            i++;j--;
        }
        return true;
    }
};