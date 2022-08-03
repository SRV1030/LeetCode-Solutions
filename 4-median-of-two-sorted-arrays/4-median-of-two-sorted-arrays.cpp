class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i=0,j=0,l1=nums1.size(),l2=nums2.size();
        vector<double>v(l1+l2);
        for(int k=0;k<l1+l2;k++){
            if(j>=l2 || (i<l1 && nums1[i]<=nums2[j])) v[k]=nums1[i++];
            else v[k]=nums2[j++];
        }
        int n=(l1+l2)/2;
        if((l1+l2)%2==0){
            int m=n-1;
            return (v[n]+v[m])/2.0;
        }
        else return v[n];
    }
};