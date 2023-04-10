class Solution {
public:
    bool isValid(string s) {
        stack<char>c;
        for(auto i:s){
            if(i=='(' || i=='{' || i=='[')c.push(i);
            else if(i==')'){
                if(c.empty() || c.top()!='(') return false;
                c.pop();
            }            
            else if(i=='}'){
               if(c.empty() || c.top()!='{') return false;
                c.pop();
            }           
            else if(i==']'){
               if(c.empty() || c.top()!='[') return false;
                c.pop();
            }
        }
        
        return c.empty();
    }
};