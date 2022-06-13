class Solution {
public:
    bool backspaceCompare(string s, string t) {  
        int i=s.size()-1,j=t.size()-1;
        for(;i>=0 || j>=0;i--,j--){
            int bks=0;
            while(i>=0 && (s[i]=='#' || bks)) s[i--]=='#'?bks++:bks--;
            bks=0;
            while(j>=0 && (t[j]=='#' || bks)) t[j--]=='#'?bks++:bks--;
            if(i>=0 && j>=0 && s[i]!=t[j]) return false;
        }
        return i==j;
    }
};