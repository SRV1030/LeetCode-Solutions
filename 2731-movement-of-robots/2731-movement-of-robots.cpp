class Solution {
public:
    int md=1e9+7;
    int sumDistance(vector<int>& nums, string s, int d) {
        for(int i=0;i<size(nums);++i){
            if(s[i]=='R')nums[i]+=d;
            else nums[i]-=d;
        }
        sort(begin(nums),end(nums));
        long pf=0,ans=0;
        for(int i=0;i<size(nums);++i){
            ans+=(long)nums[i]*i-pf;
            pf+=nums[i];
            ans%=md; 
        }
        return ans;
    }
};