// https://leetcode.com/problems/max-consecutive-ones-iii

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0,j=0,mx=-1,z=0,n=nums.size();
        while(j<n){
            if(nums[j]==0)z++;
            if(z<=k)mx=max(mx,j-i+1);
            else{
                while(i<=j && z>k){
                    if(nums[i]==0)z--;
                    i++;
                }
            }
            j++;
        }
        return mx;
    }
};