// https://leetcode.com/problems/di-string-match

class Solution {
public:
    vector<int> diStringMatch(string s) {
        int mn=0,mx=s.size();
        vector<int> ans;
        for(char i:s){
            if(i=='I')ans.push_back(mn++);
            else ans.push_back(mx--);
        }
        ans.push_back(mx);
        return ans;
    }
};