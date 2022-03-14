// https://leetcode.com/problems/smallest-subsequence-of-distinct-characters

class Solution {
public: 
    string smallestSubsequence(string s) {
        vector<int>f(26,0);
        vector<int>vis(26,0);
        stack<char>c;
        for(auto i:s) f[i-'a']++;
        for(auto i:s){
            while(!c.empty() && i<c.top() && vis[i-'a']==0 && f[c.top()-'a']>1){
                char z=c.top();
                c.pop();
                vis[z-'a']=0;  
                f[z-'a']--;
            }
            if(vis[i-'a']==0){
                c.push(i);
                vis[i-'a']=1;                
            }
        }
        string ans;
        while(!c.empty()){
            ans.push_back(c.top());
            c.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
        
};