// https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold

class Solution {
public:
    bool check(vector<int>& nums, int threshold,int k){
        int ans=0;
        for(auto& i:nums){
            ans+=(i/k);
            if(i%k)ans++;
            if(ans>threshold) return false;
        }
        return true;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l=1,r=*max_element(nums.begin(),nums.end()),res=-1;
        while(l<=r){
            int m=l+(r-l)/2;
            if(check(nums,threshold,m)){
                res=m;
                r=m-1;
            }else l=m+1;            
        }
        return res;
    }
};