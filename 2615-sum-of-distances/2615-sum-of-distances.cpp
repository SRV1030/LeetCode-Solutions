class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        unordered_map<int,long long>sml,smr,cl,cr;
        vector<long long> ans(size(nums));
        for(int i=0;i<size(nums);++i){
            ans[i]=cl[nums[i]]*i-sml[nums[i]];
            ++cl[nums[i]];
            sml[nums[i]]+=i;
        }
        for(int i=size(nums)-1;i>=0;--i){
            ans[i]+=-cr[nums[i]]*i+smr[nums[i]];
            ++cr[nums[i]];
            smr[nums[i]]+=i;
        }
        return ans;
    }
};