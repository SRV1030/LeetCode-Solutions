// https://leetcode.com/problems/generate-parentheses

class Solution {
public: vector<string> ans;
    void gen(int o,int c,string s){
        if(o==0 && c==0){
            ans.push_back(s);
            return;
        }
        if(o>0)gen(o-1,c,s+'(');
        if(c>o)gen(o,c-1,s+')');
        
    }
    vector<string> generateParenthesis(int n) {
        gen(n,n,"");
        return ans;
    }
};