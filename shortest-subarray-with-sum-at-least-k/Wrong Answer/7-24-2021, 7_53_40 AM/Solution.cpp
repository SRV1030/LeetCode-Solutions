// https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n=nums.size(),mn=INT_MAX;
        for(int i=1;i<n;i++)nums[i]+=nums[i-1];
        deque<int>dq;
        for(int i=0;i<n;i++){
            while(!dq.empty() && nums[i]-nums[dq.front()]>=k){
                mn=min(mn,i-dq.front());
                dq.pop_front();
            }
            while(!dq.empty() && nums[i]-nums[dq.front()]<0)dq.pop_back();
            dq.push_back(i);
        }
        return mn==INT_MAX?-1:mn;
    }
};