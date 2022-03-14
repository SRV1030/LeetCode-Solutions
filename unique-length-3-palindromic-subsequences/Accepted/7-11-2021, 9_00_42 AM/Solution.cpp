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
            if(n>=2){
                unordered_set<char>st;
                for(int j=i.second[0]+1;j<i.second[n-1];j++)st.insert(s[j]);
                ans+=st.size();
            }
        }
        return ans;
    }
};