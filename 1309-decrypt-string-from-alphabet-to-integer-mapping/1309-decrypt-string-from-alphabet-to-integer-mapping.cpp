class Solution {
public:
    string freqAlphabets(string s) {
        int i=0,n=size(s);
        string ans;
        while(i<n){
            if(s[i]=='1'||s[i]=='2'){
                if(i+2<n && s[i+2]=='#'){
                    string t;
                    t+=s[i];
                    t+=s[i+1];
                    ans+=('a'+stoi(t)-1);
                    i+=3;
                    continue;
                }                    
            }
            ans+=('a'+s[i]-'0'-1);
            ++i;
        }
        return ans;
    }
};