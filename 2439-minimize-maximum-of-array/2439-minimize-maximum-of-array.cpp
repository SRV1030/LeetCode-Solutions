class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        long ans=0,ps=0;
        for(int i=0;i<size(nums);++i){
            ps+=nums[i];
            ans=max(ans,(ps+i)/(i+1));
        }
        return ans;
    }
};