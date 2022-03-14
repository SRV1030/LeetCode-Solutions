// https://leetcode.com/problems/two-sum

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i=1;i<nums.size();i++){
            auto ind=find(nums.begin()+i,nums.end(),target-nums[i-1]);
            if(ind!=nums.end()){
                int j=ind-nums.begin();
                return{i-1,j};
            } 
        }
        return {-1,-1};
    }
};