class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        if(size(nums)==1) return nums[0];
        vector<int>v;
        for(int i=0;i<size(nums)/2;++i){
            if(i%2)v.emplace_back(max(nums[2*i],nums[2*i+1]));
            else v.emplace_back(min(nums[2*i],nums[2*i+1]));    
        }
        return minMaxGame(v);
    }
};