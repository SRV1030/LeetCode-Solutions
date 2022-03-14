// https://leetcode.com/problems/target-sum

class Solution {
public:
    int subsum(vector<int>& nums, int s){
        int n=nums.size();
        int t[n+1][s+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=s;j++){
                if(j==0)t[i][j]=1;
                else if(i==0) t[i][j]=0;
                else{
                    if(nums[i-1]<=j)t[i][j]=t[i-1][j]+t[i-1][j-nums[i-1]];
                    else t[i][j]=max(t[i-1][j],t[i][j-1]);
                }
            }
        }
        return t[n][s];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int s=0;
        for(auto i:nums)s+=i;
        s+=target;
        if(s%2 || s/2<target) return 0;
        s=s/2;
        return subsum(nums,s);
    }
};
