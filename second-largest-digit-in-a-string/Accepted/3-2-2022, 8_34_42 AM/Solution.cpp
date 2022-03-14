// https://leetcode.com/problems/second-largest-digit-in-a-string

class Solution {
public:
    int secondHighest(string s) {
        int l=-1,sl=-1;
        for(auto&i:s){
            if(isdigit(i)){
                int v=i-'0';
                if(v>l){
                    sl=l;
                    l=v;
                }
                else if(v<l && v>sl)sl=v;
            }
        }
        return sl;
    }
};