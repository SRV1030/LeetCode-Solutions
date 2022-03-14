// https://leetcode.com/problems/array-nesting

class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int n=nums.size();
        vector<int>f(n);
        int mx=0;
        for(auto& i:nums){
            int c=0;
            if(!f[i]){
                int x=i;
                while(!f[x]){
                    f[x]++;
                    x=nums[x];
                    c++;
                }
            }
            if(c>mx)mx=c;
        }
        return mx;
    }
};