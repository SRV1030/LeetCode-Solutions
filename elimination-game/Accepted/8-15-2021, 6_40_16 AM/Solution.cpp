// https://leetcode.com/problems/elimination-game

class Solution {
public:
    int lastRemaining(int n) {
        if(n==1)return 1;
        if(n<=4) return 2;
        if(n%2!=0) n--;
        if(n%4!=0) return 4*lastRemaining(n/4);
        return 4*lastRemaining(n/4)-2;
    }
    // int rec(int n,bool left){
    //     if(n==1) return 1;
    //     if(n%2==0 && !left){
    //         return 2*rec(n/2,!left)-1;
    //     }
    //     else  return 2*rec(n/2,!left);
    // }
};