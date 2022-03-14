// https://leetcode.com/problems/different-ways-to-add-parentheses

class Solution {
public:
    vector<int> diffWaysToCompute(string exp) {
        vector<int>op;
        int n=exp.size();
        for(int i=0;i<n;i++){
            if(!isdigit(exp[i])){                
                vector<int> x,y;
                x=diffWaysToCompute(exp.substr(0,i));
                y=diffWaysToCompute(exp.substr(i+1));
                for(auto a:x)
                    for(auto b:y){
                        if(exp[i]=='+')op.push_back(a+b);
                        else if(exp[i]=='-')op.push_back(a-b);
                        else op.push_back(a*b);
                    }
                        
            }
        }
        if(op.empty())op.push_back(stoi(exp));
        return op;
    }
};