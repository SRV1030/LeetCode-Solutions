class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int mxf=nums[0],mxc=0;
        for(auto&i:nums){
            mxc+=i;
            if(mxc>mxf)mxf=mxc;
            if(mxc<0)mxc=0;        
        }
        return mxf;
    }
};