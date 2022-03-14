// https://leetcode.com/problems/minimum-time-to-remove-all-cars-containing-illegal-goods

class Solution {
public:
    unordered_map<string,int>m;
    int solve(string s,int l,int r,int cnt){
        if(l==r)return s[l]=='1';
        if(l>r)return 0;
        string c=to_string(l)+"#"+to_string(l)+"#"+to_string(cnt);
        if(m.count(c))return m[c];
        int left=solve(s,l+1,r,(s[l]=='1')?(cnt-1):cnt)+1;
        int right=solve(s,l,r-1,(s[r]=='1')?(cnt-1):cnt)+1;
        int cur=cnt*2;
        return m[c]=min({cur,left,right});
    }
    int minimumTime(string s) {
        int n=s.size(),cnt=0;
        for(auto c:s){
            if(c=='1')cnt++;
        }
        return solve(s,0,s.size()-1,cnt);
    }
};