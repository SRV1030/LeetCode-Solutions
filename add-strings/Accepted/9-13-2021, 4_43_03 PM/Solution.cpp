// https://leetcode.com/problems/add-strings

class Solution {
public:
    string addStrings(string num1, string num2) {
        string ans="";
        int i=num1.size()-1,j=num2.size()-1,c=0;
        while(i>=0 && j>=0){
            int s=num1[i]+num2[j]+c-2*'0';
            if(s>9) c=1;
            else c=0;
            ans.push_back(s%10+'0');
            i--;j--;
        }
        while(i>=0){
            int s=num1[i]+c-'0';
            if(s>9) c=1;
            else c=0;
            ans.push_back(s%10+'0');
            i--;
        }
        while(j>=0){
            int s=num2[j]+c-'0';
            if(s>9) c=1;
            else c=0;
            ans.push_back(s%10+'0');
            j--;
        }
        if(c)ans+="1";
        reverse(ans.begin(),ans.end());
        return ans;        
    }
};