// https://leetcode.com/problems/delete-and-earn

// class Solution {
// public:
//     int deleteAndEarn(vector<int>& nums) {
//     int n = 10001;
//     vector<int> sum(n, 0);
//     vector<int> dp(n, 0);
    
//     for(auto num: nums){
//         sum[num] += num;
//     }
    
//     dp[0] = 0;
//     dp[1] = sum[1];
//     //now apply the house robbing concept
//     for(int i=2; i<n; i++){
//         dp[i] = max(dp[i-2] + sum[i], dp[i-1]);
//     }
    
//     return dp[n-1];
// }
// };

class Solution {
public:
    int dp[20001];
    int solve(vector<int>& nums, int pos){
        if(pos>=nums.size()) return 0;
        if(dp[pos]!=-1) return dp[pos];
        
        int cur = nums[pos];
        int sum = nums[pos];
        int idx = pos+1;
        
        //add all element which is equal to current element
        while(idx < nums.size() && nums[idx] == cur){
            sum+=nums[idx];
            idx++;
        }
        
        //skip all value which is equal to current value + 1;
        while(idx < nums.size() && nums[idx] == cur+1){
            idx++;
        }
        
        return dp[pos] = max(sum+solve(nums, idx), solve(nums, pos+1));
    }
    
    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        memset(dp,-1,sizeof(dp));
        return solve(nums, 0);
    }
};