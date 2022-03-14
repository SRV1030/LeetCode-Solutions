// https://leetcode.com/problems/merge-sorted-array

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=0,j=0,s=n+m;        
        vector<int> merger(s);
        for(int k=0;k<s;k++){
            if(j>=n || (i<m && nums1[i]<nums2[j])) merger[k]=nums1[i++];
            else merger[k]=nums2[j++];
            
        };
        nums1=merger;
        
    }
};