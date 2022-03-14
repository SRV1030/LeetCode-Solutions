// https://leetcode.com/problems/number-of-longest-increasing-subsequence

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<int> lis(nums.size(),1),f(nums.size(),1);
        int mx=1,ans=0;
        for(int i=1;i<nums.size();i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                    if(lis[i]<lis[j]+1)lis[i]=1+lis[j];
                    else if(lis[i]==1+lis[j])f[i]+=f[j];
                }
            }
            if(lis[i]>mx)mx=lis[i];
        }
        for(int j=0;j<nums.size();j++)if(lis[j]==mx)ans+=f[j];
        return ans;
    }
};