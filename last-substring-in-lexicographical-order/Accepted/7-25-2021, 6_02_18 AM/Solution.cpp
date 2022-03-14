// https://leetcode.com/problems/last-substring-in-lexicographical-order

class Solution {
public:
    string lastSubstring(string s) {
        char mx=s[0];
        int n=s.length(),mi=0;
        for(int i=1;i<n;i++){
            if(s[i]>mx){
                mi=i;
                mx=s[i];
            }
            else if(s[i]==mx){
                int j=1;
                while(s[i+j]==s[mi+j] && j+mi<i) j++;
                if(s[i+j]>s[mi+j])mi=i;
                i=i+j-1;
            }
        }
        return s.substr(mi,n-mi+1);
    }
};