// https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced

class Solution {
public:
    int minSwaps(string s) {
        int c=0,mx=0;
        for(auto&ch:s){
            if(ch==']')c++;
            else c--;
            mx=max(c,mx);
        }
        return (mx+1)/2;
    }
};