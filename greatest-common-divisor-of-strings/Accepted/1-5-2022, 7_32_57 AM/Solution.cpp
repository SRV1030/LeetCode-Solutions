// https://leetcode.com/problems/greatest-common-divisor-of-strings

class Solution {
public:
    bool util(string str1,string str2,int k){
        for(int i=0,j=0;i<str1.length();i++,j++)
            if(str1[i]!=str2[j%k])return false;
        return true;
    }
    string gcdOfStrings(string str1, string str2) {
        int k=__gcd(str1.size(),str2.size());
        if(util(str1,str2,k)&&util(str2,str1,k)) return str2.substr(0,k);
        return "";
    }
};