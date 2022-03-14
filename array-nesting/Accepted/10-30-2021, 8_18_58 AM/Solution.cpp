// https://leetcode.com/problems/array-nesting

class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int mx=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=-1){
                int x=i,c=0;
                while(nums[x]!=-1){
                    int t=nums[x];
                    nums[x]=-1;
                    x=t;                    
                    c++;
                }
                if(c>mx)mx=c;
            }            
        }
        return mx;
    }
};