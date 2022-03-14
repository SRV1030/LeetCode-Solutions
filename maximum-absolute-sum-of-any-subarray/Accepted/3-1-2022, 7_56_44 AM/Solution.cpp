// https://leetcode.com/problems/maximum-absolute-sum-of-any-subarray

class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int mxS=INT_MIN,mnS=INT_MAX,mxe=0,mne=0;
        for(auto&i:nums){
            mxe+=i;
            mne+=i;
            if(mxe>mxS)mxS=mxe;
            if(mne<mnS)mnS=mne;
            if(mxe<0)mxe=0;
            if(mne>0)mne=0;
        }
        return max(abs(mxS),abs(mnS));
    }
};