// https://leetcode.com/problems/maximum-repeating-substring

class Solution {
public:
    int maxRepeating(string s, string w) {
        int mx=0,nw=w.size(),n=s.size()-nw+1;
        if(n<=0) return 0;
        for(int i=0;i<n;i++){
            if(s.substr(i,nw)==w){
                int c=1,l=nw+nw;
                string t=w;
                t+=w;
                while(i+l<s.size() && t==s.substr(i,l)){
                    c++;
                    t+=w;
                    l+=nw;
                }
                i+=(l-nw);
                mx=max(mx,c);
            }
        }
        return mx;
    }
};