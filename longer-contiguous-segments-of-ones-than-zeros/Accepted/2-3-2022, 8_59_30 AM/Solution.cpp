// https://leetcode.com/problems/longer-contiguous-segments-of-ones-than-zeros

class Solution {
public:
    bool checkZeroOnes(string s) {
        int c=1,mo=0,mz=0;
        for(int i=0;i<s.size()-1;i++){
            if(s[i]==s[i+1])c++;
            else{
                if(s[i]=='0')mz=max(mz,c);
                else mo=max(mo,c);
                c=1;
            }
        }
     
            if(s[s.size()-1]=='0')mz=max(mz,c);
                else mo=max(mo,c);
            return mo>mz;
    }
};