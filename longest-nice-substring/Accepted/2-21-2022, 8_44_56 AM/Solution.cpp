// https://leetcode.com/problems/longest-nice-substring

class Solution {
public:
    string longestNiceSubstring(string s) {
        if(s.size()<2)return "";
        unordered_set<char>st(s.begin(),s.end());
        for(int i=0;i<s.size();i++){
            if(!st.count(toupper(s[i])) || !st.count(tolower(s[i]))){
                string s1= longestNiceSubstring(s.substr(0,i)),s2=longestNiceSubstring(s.substr(i+1));
                return s1.size()>=s2.size()?s1:s2;
            }
        }
        return s;
    }
};