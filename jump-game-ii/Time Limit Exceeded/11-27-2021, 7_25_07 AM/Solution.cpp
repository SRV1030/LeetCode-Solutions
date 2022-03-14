// https://leetcode.com/problems/jump-game-ii

class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> pos(nums.size()),mis(nums.size(),INT_MAX-1);
        mis[0]=0;
        for(int i=1;i<nums.size();i++)
            for(int j=0;j<i;j++){
                if(nums[j]+j>=i){
                    if(mis[j]+1<mis[i]){
                        pos[i]=j;
                        mis[i]=1+mis[j];
                    }
                }
            }
        return mis[nums.size()-1];
    }
};