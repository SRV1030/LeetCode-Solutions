// https://leetcode.com/problems/first-unique-character-in-a-string

class Solution {
public:
int firstUniqChar(string s) {
        int n = s.length();
        vector<int> dp(26);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            dp[s[i] - 'a']++;
            if (dp[s[i] - 'a'] == 1) st.push(i);
            else if (!st.empty() && s[i] == s[st.top()]) {
                while (!st.empty() && dp[s[st.top()] - 'a'] > 1) st.pop();
            }
        }
        
        return st.empty() ? -1 : st.top();
    }
};