// https://leetcode.com/problems/final-value-of-variable-after-performing-operations

class Solution {
public:
    int finalValueAfterOperations(vector<string>& op) {
        int ans=0;
        for(auto o:op){
            if(o[0]=='+'||o[2]=='+')ans++;
            else ans--;
        }
        return ans;
    }
};