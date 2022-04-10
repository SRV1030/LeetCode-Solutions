class Solution {
public:
    bool check(vector<int>& nums) {
        int hl=0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]>nums[i+1])hl++;
            if(hl>=2) return false;
        }
        if(nums[nums.size()-1]>nums[0])hl++;
        return hl<=1;
    }
};