// https://leetcode.com/problems/string-to-integer-atoi

class Solution {
public:
    int removeSpace(string s){
        int i=0;
        while(i<s.size() && s[i]==' ')i++;
        return i;
    }
    int getInt(int i,string s,bool neg){
        long int ans=0;
        while(i<s.size()){
            if(s[i]>='0' && s[i]<='9'){
                ans=(ans*10)+(s[i]-'0');
                if(ans>INT_MAX){
                    if(neg) return INT_MIN;
                    return INT_MAX;
                }
                i++;
            }
        }
        if(neg) return -1*ans;
        return ans;
    }
    int myAtoi(string s) {
        int n=s.size();
        int i=removeSpace(s);
        bool neg=0;
        if(s[i]=='+' || s[i]=='-'){
            if(s[i]=='-') neg=1;
            i++;
        }
        return getInt(i,s,neg);
    }
};