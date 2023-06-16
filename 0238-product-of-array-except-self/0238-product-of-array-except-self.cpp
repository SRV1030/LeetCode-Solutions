class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n);
        for(int i=0,p=1;i<n;i++){
            ans[i]=p;
            p*=nums[i];
        }
        for(int i=n-2,p=nums[n-1];i>=0;i--){
            ans[i]*=p;
            p*=nums[i];
        }
        return ans;
    }
};