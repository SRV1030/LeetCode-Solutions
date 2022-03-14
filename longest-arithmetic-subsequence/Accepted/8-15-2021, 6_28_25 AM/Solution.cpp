// https://leetcode.com/problems/longest-arithmetic-subsequence

class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int mx=2,n=nums.size();
        vector<vector<int>>mp(1001,vector<int>(1001,1));
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                int dif=nums[i]-nums[j]+500;
                if(mp[i][dif]<mp[j][dif]+1)mp[i][dif]=mp[j][dif]+1;
                if(mx<mp[i][dif])mx=mp[i][dif];
            }
        }        
        return mx;
    }
};