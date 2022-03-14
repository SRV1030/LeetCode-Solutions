// https://leetcode.com/problems/first-missing-positive

class Solution {
public:
    int sep(vector<int>& nums){
        int z=0,i=0;
        for(int i=0;i<nums.size();i++)
            if(nums[i]<=0)swap(nums[i],nums[z++]);
        return z;
    }
    int firstMissingPositive(vector<int>& num) {
        int shift=sep(num);
        vector<int>nums(num.begin()+shift,num.end());
        int s=0,e=nums.size();
        for(int i=s;i<e;i++){
            if(abs(nums[i])-1<e && nums[abs(nums[i])-1]>0)nums[abs(nums[i])-1]=-nums[abs(nums[i])-1];
        }
        for(int i=0;i<e;i++)
            if(nums[i]>0)
                 return i+1;
        return e+1;
    }
};