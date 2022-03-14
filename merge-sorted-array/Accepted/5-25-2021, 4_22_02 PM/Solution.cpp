// https://leetcode.com/problems/merge-sorted-array

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> merger;
        int i=0,j=0;
        while(i<m && j<n){                       
            if(nums1[i]<nums2[j])merger.push_back(nums1[i++]);
            else if(nums1[i]>nums2[j])merger.push_back(nums2[j++]);
            else {
                merger.push_back(nums2[j++]);
                merger.push_back(nums1[i++]);
            }            
        }
        while(i<m)merger.push_back(nums1[i++]);
        while(j<n)merger.push_back(nums2[j++]);
        nums1=merger;
        
    }
};