// https://leetcode.com/problems/form-array-by-concatenating-subarrays-of-another-array

class Solution {
public:
    bool canChoose(vector<vector<int>>& g, vector<int>& nums) {
        int i=0,j=0;
        for(int k=0;k<nums.size();k++){
            if(nums[k]==g[i][j]){
                j++;
                if(j==g[i].size()){
                    i++;
                    if(i==g.size())return true;
                    j=0;
                }
            }else{
                k=k-j;
                j=0;
            }
        }
        return false;
    }
};