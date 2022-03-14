// https://leetcode.com/problems/multiply-strings

class Solution {
public:
    string multiply(string num1, string num2) {
        int n1=num1.size(),n2=num2.size(),shift1=0,shift2=0,c=0;
        vector<int>s(n1+n2+1);
        for(int i=n1-1;i>=0;i--){
            shift2=0;
            c=0;
            int m1=num1[i]-'0';
            for(int j=n2-1;j>=0;j--){
                int m2=num2[j]-'0';
                int r=m1*m2+s[shift1+shift2]+c;
                c=r/10;
                s[shift1+shift2]=r%10;
                shift2++;                
            }
            if(c>0)s[shift1+shift2]+=c;
            shift1++;
        }
        int i=n1+n2;
        while(i>=0 && s[i]==0)i--;
        if(i==-1) return "0";
        string ans="";
        while(i>=0){
            ans+=to_string(s[i]);
            i--;
        } 
        return ans;
            
    }
};