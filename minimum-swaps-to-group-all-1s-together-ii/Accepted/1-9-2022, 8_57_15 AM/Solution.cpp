// https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together-ii

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int f=-1,no=0,i,j;
        for(int x=0;x<nums.size();x++){
            if(nums[x]){
                if(f==-1)f=x;
                no++;
            }
        }
        if(no==nums.size() || f==-1)return 0;
        int mx1=0,c1=0;
        i=f;
        for(j=0;j<no;j++){
            if(nums[i])c1++;
            i++;
            if(i==nums.size())i=0;
        }
        mx1=c1;
        i=f+1;
        while(i!=f){
            int ind1=(i-1)==-1?nums.size()-1:i-1,ind2=(i+no-1)%nums.size();
            if(nums[ind1])c1--;
            if(nums[ind2])c1++;
            if(c1>mx1)mx1=c1;
            i++;
            if(i==nums.size())i=0;            
        }
        return no-mx1;
    }
};