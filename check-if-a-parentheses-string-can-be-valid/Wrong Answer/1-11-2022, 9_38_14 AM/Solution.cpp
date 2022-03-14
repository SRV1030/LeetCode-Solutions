// https://leetcode.com/problems/check-if-a-parentheses-string-can-be-valid

class Solution {
public:
    bool canBeValid(string s, string locked) {
        if(s.size()%2) return false;
        int cnt=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(' || locked[i]=='0')cnt++;
            else cnt--;
            if(cnt<0) return false;
        }
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='(' || locked[i]=='0')cnt++;
            else cnt--;
            if(cnt<0) return false;
        }
        return true;
    }
};