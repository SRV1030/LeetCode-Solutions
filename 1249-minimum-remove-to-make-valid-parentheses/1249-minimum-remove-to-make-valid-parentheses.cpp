class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int c=0;
        for(auto&i:s){
            if(i=='(')++c;
            else if(i==')'){
                if(!c)i='#';
                else --c;
            }
        }
        c=0;
        for(int i=size(s)-1;i>=0;--i){
            if(s[i]==')')++c;
            else if(s[i]=='('){
                if(!c)s[i]='#';
                else --c;
            }
        }
        string ans;
        for(auto&i:s)if(i!='#')ans+=i;
        return ans;
    }
};