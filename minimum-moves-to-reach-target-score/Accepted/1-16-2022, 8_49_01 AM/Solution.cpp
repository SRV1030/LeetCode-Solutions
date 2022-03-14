// https://leetcode.com/problems/minimum-moves-to-reach-target-score

class Solution {
public:
    int minMoves(int t, int m) {
        int ans=0;
        while(m&&t!=1){
            if(t%2){
                t--;
                ans++;
            }
            t=t/2;
            ans++;
            m--;
        }
        return ans+t-1;
    }
};