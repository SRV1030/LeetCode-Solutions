// https://leetcode.com/problems/find-first-palindromic-string-in-the-array

class Solution {
public:
    bool check(string s){
        int lo=0,hi=s.length()-1;
        while(lo<hi){
            if(s[lo]!=s[hi]){
                return false;
            }
            lo++;hi--;
        }
        return true;
    }
    string firstPalindrome(vector<string>& words) {
        for(auto word:words){
            if(check(word))return word;
        }
        return "";
    }
};