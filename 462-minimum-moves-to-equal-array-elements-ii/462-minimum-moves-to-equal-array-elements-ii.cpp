class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(begin(nums),end(nums));
        int ans=0,md=nums[size(nums)/2];
        for(auto&i:nums)ans+=abs(i-md);
        return ans;
    }
};