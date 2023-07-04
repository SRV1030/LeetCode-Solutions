class Solution {
public:
    int singleNumber(vector<int>& nums) {
        long ans=0,n=size(nums);
        for(int i=0;i<32;++i){
            int t=0;
            for(int j=0;j<n;++j){
                int x=nums[j]&1;
                t+=x;
                nums[j]>>=1;
            }
            t%=3;
            ans+=t*pow(2,i);
        }
        return ans;
    }
};