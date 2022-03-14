// https://leetcode.com/problems/all-divisions-with-the-highest-score-of-a-binary-array

class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        int one=0,zero=0;
        vector<int>ans;
        for(auto num:nums)one+=(num==1);
        int mx=one,o=one,z=0;
        for(auto num:nums){
            if(num==0){
                zero++;
            }else{
                one--;
            }
            mx=max(mx,zero+one);
        }
        if(mx==o){
            ans.push_back(0);
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                o--;
            }else{
                z++;
            }
            if(mx==o+z){
                ans.push_back(i+1);
            }
        }
        return ans;
    }
};