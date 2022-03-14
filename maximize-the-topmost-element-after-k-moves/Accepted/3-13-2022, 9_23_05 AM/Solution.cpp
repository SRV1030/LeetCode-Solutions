// https://leetcode.com/problems/maximize-the-topmost-element-after-k-moves

class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        int n=nums.size();
        if(k==0)return nums[0];
        if(n==1)return k%2==1?-1:nums[0];
        if(k%2==1){
            int mx=-1;
            if(n<k)return *max_element(nums.begin(),nums.end());
            else if(n==k){
                for(int i=0;i<k-1;i++){
                    mx=max(mx,nums[i]);
                }
                return mx;
            }else{
                for(int i=0;i<k-1;i++){
                    mx=max(mx,nums[i]);
                }
                return max(mx,nums[k]);
            }
        }else{
            int mx=-1;
            if(n<k)return *max_element(nums.begin(),nums.end());
            else if(n==k){
                for(int i=0;i<k-1;i++){
                    mx=max(mx,nums[i]);
                }
                return mx;
            }else{
                for(int i=0;i<k-1;i++){
                    mx=max(mx,nums[i]);
                }
                return max(mx,nums[k]);
            }
        }
        return -1;
    }
};