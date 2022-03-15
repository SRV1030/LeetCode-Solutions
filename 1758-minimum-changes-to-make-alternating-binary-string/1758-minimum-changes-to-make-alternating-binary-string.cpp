class Solution {
public:
    int minOperations(string s) {
        int ch1=0,ch2=0;
        for(int i=0;i<s.size();i++)
            if((i%2 && s[i]=='0')||i%2==0 && s[i]=='1')ch1++;        
        for(int i=0;i<s.size();i++)
            if((i%2 && s[i]=='1')||i%2==0 && s[i]=='0')ch2++;
        return min(ch1,ch2);
    }
};