class Solution {
public:
    int maxSum(vector<int>& nums) {
        vector<int>v(10);
        int ans=0;
        for(auto&i:nums){
            int mx=0,j=i;
            while(j){
                mx=max(mx,j%10);
                j/=10;
            }
            if(v[mx])ans=max(ans,v[mx]+i);
            v[mx]=max(v[mx],i);
        }
        return !ans?-1:ans;
    }
};