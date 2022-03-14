// https://leetcode.com/problems/integer-replacement

class Solution {
public:map<int,int>dp;
    int integerReplacement(int n) {
        if(n==1) return 0;
        if(n==2) return 1;
        if(n==INT_MAX) return 32;
        if(!dp.count(n)){
            if(n%2==0) dp[n]=integerReplacement(n/2)+1;
            else dp[n]=min(integerReplacement(n-1),integerReplacement(n+1))+1;
        }
        return dp[n];
    }
};