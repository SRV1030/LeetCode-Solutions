// https://leetcode.com/problems/consecutive-characters

class Solution {
public:
    int maxPower(string s) {
        int c=1,mx=1;
        for(int i=0;i<s.size()-1;i++){
            if(s[i]==s[i+1])c++;
            else{
                if(c>mx)mx=c;
                c=1;
            }
        }
        return max(c,mx);
    }
};