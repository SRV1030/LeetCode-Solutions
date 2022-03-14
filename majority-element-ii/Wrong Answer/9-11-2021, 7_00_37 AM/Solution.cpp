// https://leetcode.com/problems/majority-element-ii

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int c1=0,c2=0,e1=-1,e2=-1,d=nums.size()/3;
        for(auto &i:nums){
            if(e1==i)c1++;
            else if(e2==i)c2++;
            else if(c1==0){
                e1=i;
                c1=1;
            }
            else if(c2==0){
                e2=i;
                c2=1;
            }
            else{
                c1--;
                c2--;
            }
        }
        c1=c2=0;
        for(auto&i:nums){
            if(i==e1)c1++;
            else if(i==e2)c2++;
        }
        if(c1>d && c2>d)return {e1,e2};
        if(c2>d)return {e2};
        return {e1};
    }
};