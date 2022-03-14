// https://leetcode.com/problems/find-the-town-judge

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int m=trust.size();
        if(m==0){
            if(n==1) return 1;
            else return -1;
        }
        vector<int>t(n+1);
        for(auto&i:trust){
            t[i[0]]--;
            t[i[1]]++;
        }
        for(int i=1;i<n+1;i++)
            if(t[i]==n-1) return i;
        return -1;
    }
};