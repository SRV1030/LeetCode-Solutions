// https://leetcode.com/problems/basic-calculator

class Solution {
public:
    long long int calculate(string s) {
        long long int res=0,v=0,sign=1;
        stack<int>st;
        for(auto& i:s){
            if(isdigit(i)) v=v*10+i-'0';
            else if(i=='+'){
                res+=v*sign;
                v=0;
                sign=1;
            }
            else if(i=='-'){
                res+=v*sign;
                v=0;
                sign=-1;
            }
            else if(i=='('){
                st.push(res);
                st.push(sign);
                res=0;
                sign=1;
            }
             else if(i==')'){                
                res+=v*sign;
                res*=st.top();
                st.pop();
                res+=st.top();
                st.pop();
                v=0;
                sign=1;
            }
            // cout<<v<<" "<<res<<"\n";
        }
        if(v>0) res+=v*sign;
        return res;
    }
};