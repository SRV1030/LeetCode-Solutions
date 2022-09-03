class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {        
        int i=0,j=0,c=0;
        for(;j<size(s);++j){
            c+=abs(s[j]-t[j]);
            if(c>maxCost) c-=abs(s[i]-t[i++]);
        }
        return j-i;
    }
};