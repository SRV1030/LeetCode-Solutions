class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ele=0,c=0;
        for(auto&i:nums){
            if(c==0) ele=i;
            if(ele==i)c++;
            else c--;
        }
        return ele;
    }
};