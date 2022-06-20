class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        int n=size(s);
        string ans(n,' ');
        for(int i=0;i<size(s);++i)ans[indices[i]]=s[i];
        return ans;
    }
};