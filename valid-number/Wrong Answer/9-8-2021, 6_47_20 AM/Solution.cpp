// https://leetcode.com/problems/valid-number

class Solution {
public:
    bool isNumber(string s) {        
        int i=0,n=s.size();
        if(!isdigit(s[n-1]) && s[n-1]!='.') return false;
        if(n==2 && !isdigit(s[0]) && s[0]!='.' ) return false;
        bool d=false,e=false;
        for(i=0;i<n;i++){
            if(isdigit(s[i])) continue;
            if(s[i]=='+' || s[i]=='-'){       
                if(i==0) continue;
                if(i-1>=0 && (s[i-1]=='E' || s[i-1]=='e')) continue;
                return false;
            }
            if(isalpha(s[i]) && s[i]!='E' && s[i]!='e') return false;
            if(s[i]=='E' || s[i]=='e'){
                if(e || i==0) return false;
                if(i+1>=s.size() || (!isdigit(s[i+1]) && s[i+1]!='+' && s[i+1]!='-'))return false;
                e=true;
            }
            else if(s[i]=='.'){
                if(e || d || n==1 || (i+1<s.size() && isalpha(s[i+1]))) return false;
                d=true;
            }
        }
        return true;
    }
};