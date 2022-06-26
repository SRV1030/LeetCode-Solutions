class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int f=0;
        for(int i=1;i<size(nums);++i){
            if(nums[i]<nums[i-1]){
                if(++f>1) return false;
                if(i==1 || nums[i-2]<=nums[i])nums[i-1]=nums[i];
                else nums[i]=nums[i-1];
            }
        }
        return true;
    }
};