class Solution {
public:
    string modifyString(string s) {
        for(int i=0;i<size(s);++i){
            if(s[i]=='?'){
                int prev=(i==0)?-1:s[i-1]-'a',nxt=(i==size(s)-1)?-1:s[i+1]-'a';
                for(char x='a';x<='z';++x){                    
                    if(prev!=-1 && (prev==x-'a' || prev==x-'a'-1))continue;
                    if(nxt!=-1 && (nxt==x-'a' || nxt==x-'a'+1))continue;
                    s[i]=x;
                    break;
                }
            }
        }
        return s;
    }
};