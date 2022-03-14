// https://leetcode.com/problems/minimum-moves-to-convert-string

class Solution {
public:
    int minimumMoves(string s) {
        int x=0,c=0,ans=0,i=0,n=s.size();
        while(i<n&&s[i]!='X')i++;
        for(;i<n;i++){
            c++;
            if(s[i]=='X')x++;
            if(c==3){
                if(x)ans++;
                x=0;c=0;
            }
        }
        return x?ans+1:ans;
    }
};