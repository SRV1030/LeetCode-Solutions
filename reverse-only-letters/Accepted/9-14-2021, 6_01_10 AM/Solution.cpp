// https://leetcode.com/problems/reverse-only-letters

class Solution {
public:
    string reverseOnlyLetters(string s) {
        int n=s.length();
        for(int i=0,j=n-1;i<j;i++,j--){
            while(i<j && !isalpha(s[i]))i++;
            while(j>i && !isalpha(s[j]))j--;
            swap(s[i],s[j]);
        }
        return s;
    }
};