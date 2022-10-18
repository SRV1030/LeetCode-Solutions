class Solution {
public:
    string countAndSay(int n) {
        string s="1";
        if(n==1) return s;
        for(int i=1;i<n;i++){
            string t="";
            int c=1;
            char ch=s[0];
            for(int j=1;j<s.size();j++){
                if(s[j]==ch)c++;
                else {
                    t+=to_string(c)+ch;
                    ch=s[j];
                    c=1;
                }
            }
            t+=to_string(c)+ch;
            s=t;
        }
        return s;
    }
};