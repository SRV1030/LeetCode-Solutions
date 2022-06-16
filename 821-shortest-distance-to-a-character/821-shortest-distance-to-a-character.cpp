class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int>ans(size(s));
        int prev=-100000;
        for(int i=0;i<size(s);++i){
            if(s[i]==c)prev=i;
            else ans[i]=i-prev;
        }
        prev=100000;
        for(int i=size(s)-1;i>=0;--i){
            if(s[i]==c)prev=i;
            else ans[i]=min(ans[i],prev-i);;
        }
        return ans;
    }
};