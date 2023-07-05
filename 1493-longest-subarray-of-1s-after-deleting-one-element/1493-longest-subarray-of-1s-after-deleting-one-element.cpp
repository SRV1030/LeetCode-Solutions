class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int pv=0,cz=0,ans=0;
        for(int i=0;i<size(nums);++i){
            if(!nums[i])++cz;
            while(cz>1){
                if(!nums[pv])--cz;
                ++pv;
            }
            ans=max(ans,i-pv);
        }
        return ans;
    }
};