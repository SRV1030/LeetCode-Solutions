// https://leetcode.com/problems/target-sum

class Solution {
public:
    int subsum(vector<int>& nums, int s){
        int n=nums.size();
        int t[n+1][s+1];
        for(int i=0;i<=n;i++){
            t[i][0]=1;
        }        
        for(int i=1;i<=s;i++){
            t[0][i]=0;
        }
        for(int i=1;i<=n;i++){
            for(int j=0;j<=s;j++){
                    if(nums[i-1]<=j)t[i][j]=t[i-1][j]+t[i-1][j-nums[i-1]];
                    else t[i][j]=t[i-1][j];
                
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
