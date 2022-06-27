class Solution {
public:
    int countAsterisks(string s) {
        int c=0,f=0;
        for(auto&i:s){
            if(i=='*' && !f)++c;
            if(i=='|')f=!f;
        }
        return c;
    }
};