// https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int c=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(')c++;
            else if(s[i]==')'){
                if(!c)s[i]='#';
                else c--;
            }
        }
        c=0;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]==')')c++;
            else if(s[i]=='('){
                if(!c)s[i]='#';
                else c--;
            }
        }
        string ans;
        for(int i=0;i<s.size();i++)
            if(s[i]!='#')ans+=s[i];   
         return ans;   
    }
};