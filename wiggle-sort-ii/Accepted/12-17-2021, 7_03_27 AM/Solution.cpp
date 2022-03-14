// https://leetcode.com/problems/wiggle-sort-ii

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
       vector<int> tmp=nums;
        sort(tmp.begin(),tmp.end());
        int x=nums.size()/2;
        int y=nums.size()-x;
        
        int i=1,k=nums.size()-1;
        while(x--){
            nums[i]=tmp[k--];
            i+=2;
        }
        
        i=0;
        while(y--){
            nums[i]=tmp[k--];
            i+=2;
        }
    }
};