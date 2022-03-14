// https://leetcode.com/problems/add-strings

class Solution {
public:
    string addStrings(string num1, string num2) {
        string ans="";
        int i=num1.size()-1,j=num2.size()-1,c=0;
        while(c || i>=0 || j>=0){
            if(i>=0)c+= num1[i--]-'0';
            if(j>=0)c+= num2[j--]-'0';
            ans+=(c%10+'0');
            c/=10;
        }
        reverse(ans.begin(),ans.end());
        return ans;        
    }
};