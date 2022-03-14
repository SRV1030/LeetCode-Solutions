// https://leetcode.com/problems/sort-colors

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size(),z=-1,t=n;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                z++;
                swap(nums[z],nums[i]);
            }
        }
        for(int j=n-1;j>=0 && nums[j]!=0;j--){            
            if(nums[j]==2){
                t--;
                swap(nums[t],nums[j]);
            }
        }
    }
};