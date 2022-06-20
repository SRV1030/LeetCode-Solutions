class Solution {
public:
    string greatestLetter(string s) {
        vector<int>F(36),f(26);
        for(auto&i:s){
            if(i<'a')++F[i-'A'];
            else ++f[i-'a'];
        }
        for(int i=25;i>=0;--i)
            if(F[i] && f[i]){
                char a=(char)(i+'A');
                string s;
                s+=a;
                return s;
            }
        return "";
    }
};