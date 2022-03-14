// https://leetcode.com/problems/number-of-times-binary-string-is-prefix-aligned

class Solution {
public:
    int numTimesAllBlue(vector<int>& light) {
        int rm=-1,c=0;
        for(int i=0;i<light.size();i++){
            rm=rm>light[i]?rm:light[i];
            if(rm==i+1)c++;
        }
        return c;
    }
};