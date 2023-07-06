class Solution {
public:
    int minSubArrayLen(int t, vector<int>& nums) {
        int l=0,r=0,s=0,n=nums.size(),mn=INT_MAX;
        while(r<n){
            while(r<n && s<t)s+=nums[r++];
            while(l<r && s>=t){
                if(r-l<mn)mn=r-l;
                s-=nums[l++];
            }                
        }
        return mn==INT_MAX?0:mn;
    }
};