// https://leetcode.com/problems/destroying-asteroids

class Solution {
public:
    bool asteroidsDestroyed(long long int mass, vector<int>& ast) {
        sort(ast.begin(),ast.end());
        for(auto&i:ast){
            if(mass<i)return false;
            mass+=i;
        }
        return true;
    }
};