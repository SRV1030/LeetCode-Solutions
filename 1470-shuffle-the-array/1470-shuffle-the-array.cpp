class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        for(int i=n;i<size(nums);++i)nums[i]=nums[i]*1024+nums[i-n];
        for(int id=0,i=n;i<size(nums);++i,id+=2){
            nums[id]=nums[i]%1024;
            nums[id+1]=nums[i]/1024;
        }
        return nums;
    }
};