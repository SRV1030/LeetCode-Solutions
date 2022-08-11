class Solution {
public:
    int minimumSwap(string s1, string s2) {
        if(size(s1)!=size(s2)) return -1;
        int x=0,y=0;
        for(int i=0;i<size(s1);++i)
            if(s1[i]!=s2[i])s1[i]=='x'?++x:++y;
        if((x+y)%2)return-1;
        int ans=(x+y)/2;
        ans+=x%2;
        return ans;
    }
};