// https://leetcode.com/problems/generate-parentheses

class Solution {
public:
    vector<string> v;   
    void Fill(int o,int c,string s){
        if(c==0 && o==0){
            v.push_back(s);
            return;
        }
        if(o>0) Fill(o-1,c,s+'(');       
        if(c>o) Fill(o,c-1,s+')');
    }
    vector<string> generateParenthesis(int n) {
        v.clear();
        Fill(n,n,"");
        return v;
    }
};