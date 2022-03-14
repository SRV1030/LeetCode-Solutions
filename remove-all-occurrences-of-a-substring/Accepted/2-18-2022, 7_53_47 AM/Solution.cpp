// https://leetcode.com/problems/remove-all-occurrences-of-a-substring

class Solution {
public: int n=0;
    void rem(string &s,string &part){
        if(s.size()<n) return;
        for(int i=0;i<s.size()-n+1;i++){
            if(s.substr(i,n)==part){
                s.erase(i,n);
                rem(s,part);
                break;
            }
        }
    }
    string removeOccurrences(string s, string part) {
        n=part.size();
        rem(s,part);
        return s;
    }
};