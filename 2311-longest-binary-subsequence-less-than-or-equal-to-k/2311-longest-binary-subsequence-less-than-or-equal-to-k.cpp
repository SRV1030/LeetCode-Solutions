class Solution {
public:
    int longestSubsequence(string s, int k) {
        int v=0,cnt=0,p=1;
        for(int i=size(s)-1;i>=0 && (v+p)<=k;--i){
            if(s[i]=='1'){
                ++cnt;
                v+=p;
            }
            p<<=1;
        }
        return count(begin(s),end(s),'0')+cnt;
    }
};