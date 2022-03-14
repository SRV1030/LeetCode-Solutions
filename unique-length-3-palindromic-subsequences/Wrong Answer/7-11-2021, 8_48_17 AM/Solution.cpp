// https://leetcode.com/problems/unique-length-3-palindromic-subsequences

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        map<char,vector<int>>mp;
        for(int i=0;i<s.length();i++){
            mp[s[i]].push_back(i);
        }
        int ans=0;
        for(auto i:mp){
            int n=i.second.size();
            if(n==2) ans+=(i.second[1]-i.second[0]-1);
            else if(n>2) ans+=(i.second[n-1]-i.second[0]-n+2);
        }
        return ans;
    }
};