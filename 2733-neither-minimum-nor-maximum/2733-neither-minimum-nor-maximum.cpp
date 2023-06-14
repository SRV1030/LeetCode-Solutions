class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        if(size(nums)<3) return -1;
        int mn=min({nums[0],nums[1],nums[2]}),mx=max({nums[0],nums[1],nums[2]});
        for(int i=0;i<3;++i)if(nums[i]!=mx && nums[i]!=mn)return nums[i];
        return -1;
    }
};