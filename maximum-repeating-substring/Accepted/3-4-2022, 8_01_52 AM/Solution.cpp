// https://leetcode.com/problems/maximum-repeating-substring

class Solution {
public:
    int maxRepeating(string s, string w) {
        int mx=0,nw=w.size(),n=s.size();
        if(nw>n) return 0;
        for(int i=0;i<n;i++){
            int k=i,c=0;
            while(k<n && s.substr(k,nw)==w){
                k+=nw;
                c++;
            }
            mx=max(mx,c);
        }
        return mx;
    }
};