// https://leetcode.com/problems/evaluate-reverse-polish-notation

class Solution {
public:
    bool isop(string x){
        return x=="+" || x=="*" || x=="/" || x=="-";
    }
    
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(auto i:tokens){
            if(!isop(i)) st.push(stoi(i));
            else{
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();                
                switch(i[0]){
                    case '+': st.push(a+b);
                               break;
                    case '-': st.push(b-a);
                               break;
                    case '/': st.push(b/a);
                               break;
                    case '*': st.push(a*b);
                               break;
                }
            }
            // cout<<st.top()<<" ";
        }
        return st.top();
    }
};