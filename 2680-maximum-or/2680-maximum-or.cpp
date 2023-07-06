class Solution {
public:
    long long maximumOr(vector<int>& nums, int k) {
        long long ans=0,mul=1<<k;
        vector<long> pre(size(nums),0),suf(size(nums),0);
        pre[0]=nums[0];
        suf[size(nums)-1]=nums[size(nums)-1];
        for(int i=1;i<size(nums);++i){
            pre[i]=pre[i-1]|nums[i];
            suf[size(nums)-i-1]=suf[size(nums)-i]|nums[size(nums)-i-1];
        }
        for(int i=0;i<size(nums);++i){
            long long t=nums[i]*mul;
            if(i>0)t|=pre[i-1];
            if(i<size(nums)-1)t|=suf[i+1];
            ans=max(ans,t);
        }
        return ans;
    }
};