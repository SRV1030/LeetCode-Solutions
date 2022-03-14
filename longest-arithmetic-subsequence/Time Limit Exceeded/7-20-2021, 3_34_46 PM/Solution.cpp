// https://leetcode.com/problems/longest-arithmetic-subsequence

class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int mx=2,n=nums.size();
        vector<map<int,int>>mp(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                int x=nums[i]-nums[j];
                if(!mp[j].count(x)){
                    mp[i][x]=2;
                }
                else{
                     mp[i][x]=mp[j][x]+1;
                    if(mp[i][x]>mx)mx=mp[i][x];
                }
            }
        }        
        return mx;
    }
};