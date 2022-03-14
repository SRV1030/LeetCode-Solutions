// https://leetcode.com/problems/maximum-distance-between-a-pair-of-values

class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int i=0,j=0,ns1=nums1.size(),ns2=nums2.size(),mxd=0;
        while(i<ns1){
            while(j<ns2 && nums2[j]>=nums1[i])j++;            
            mxd=max(mxd,j-i-1);
            if(j==ns2)break;
            i++;
        }
        return mxd;
    }
};