// https://leetcode.com/problems/determine-if-string-halves-are-alike

class Solution {
public:
    bool halvesAreAlike(string s) {
        int n=s.size();
        if(n%2)return false;
        int vc=0;
        for(auto&i:s)
            if(i=='a' || i=='e'||i=='i'|| i=='o'|| i=='u'|| i=='A' ||i== 'E'|| i== 'I'|| i== 'O'|| i=='U')vc++;
        if(vc%2)return false;
        return true;
    }
};