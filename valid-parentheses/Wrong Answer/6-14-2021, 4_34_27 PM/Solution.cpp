// https://leetcode.com/problems/valid-parentheses

class Solution {
public:
    bool isValid(string s) {
        stack<char>c;
        stack<char>m;
        stack<char>b;
        for(auto i:s){
            if(i=='(')c.push('(');
            else if(i==')'){
                if(c.empty()) return false;
                c.pop();
            }
            if(i=='{')m.push('{');
            else if(i=='}'){
                if(m.empty()) return false;
                m.pop();
            }
            if(i=='[')b.push('[');
            else if(i==']'){
                if(b.empty()) return false;
                b.pop();
            }
        }
        
        return true;
    }
};