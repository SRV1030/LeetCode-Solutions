// https://leetcode.com/problems/merge-sorted-array

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int l=0,r=0,k=m+n;
        vector<int>ans(k);
        for(int i=0;i<k;i++){
            if(r>=n || (l<m && nums1[l]<nums2[r]))ans[i]=nums1[l++];
            else ans[i]=nums2[r++];
        }
        nums1=ans;
    }
};