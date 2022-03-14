// https://leetcode.com/problems/jump-game-vi

class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        vector<int> dp(nums.size());
        priority_queue<pair<int,int>> pq;
        dp[0] = nums[0];
        pq.push({nums[0],0});
        for(int i=1;i<nums.size();i++){
            dp[i]=nums[i];
            while(pq.top().second+k<i)pq.pop();
            dp[i]+=pq.top().first;
            pq.push({dp[i],i});
        }
        return dp[nums.size()-1];
    }
};