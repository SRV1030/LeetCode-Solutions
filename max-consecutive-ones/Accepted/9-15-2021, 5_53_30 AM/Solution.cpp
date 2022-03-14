// https://leetcode.com/problems/max-consecutive-ones

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int c=0,mx=0;
        for(auto& i:nums){
            if(i)c++;
            else if(c){
                if(c>mx)mx=c;
                c=0;
            }
        }
        if(c>mx)mx=c;
        return mx;
    }
};