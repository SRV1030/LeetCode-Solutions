// https://leetcode.com/problems/word-break

class Solution {
public:
    unordered_map<string,bool>dp;
    bool wordBreak(string s, vector<string>& wd) {
        int n=s.length();
        if(n==0) return true;
        if(dp.count(s))return dp[s];
        for(int i=1;i<=n;i++){
            string ss=s.substr(0,i);
            if(find(wd.begin(),wd.end(),ss)!=wd.end()){
                dp[ss]=true;
                if(wordBreak(s.substr(i),wd)) return dp[s]=true;
            }
        }
        return dp[s]=false;
    }
};