class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int>fr(k);
        int c=0,s=0;
        fr[0]=1;
        for(auto&i:nums){
            s+=i;
            int rm=(s%k);
            if(rm<0)rm+=k;
            c+=fr[rm];
            fr[rm]++;            
        }
        return c;
    }
};

// https://leetcode.com/problems/subarray-sums-divisible-by-k/discuss/413234/DETAILED-WHITEBOARD!-BEATS-100-(Do-you-really-want-to-understand-It)