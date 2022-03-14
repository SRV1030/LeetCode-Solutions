// https://leetcode.com/problems/incremental-memory-leak

class Solution {
public:
    vector<int> memLeak(int m1, int m2) {
        int i=1;
        while(i<=m1 || i<=m2){
            if(m1>=m2)m1-=i;
            else m2-=i;
            i++;
        }
        return {i,m1,m2};
    }
};