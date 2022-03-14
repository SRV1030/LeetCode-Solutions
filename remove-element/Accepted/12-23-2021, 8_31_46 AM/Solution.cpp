// https://leetcode.com/problems/remove-element

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i=0,n=nums.size();
        while(i<n){
            if(nums[i]==val){
                nums[i]=nums[n-1];
                n--;
            }
            else i++;
        }
        return n;
    }
};