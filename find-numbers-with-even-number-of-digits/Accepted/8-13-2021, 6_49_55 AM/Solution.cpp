// https://leetcode.com/problems/find-numbers-with-even-number-of-digits

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int c=0;
        for(auto& i:nums){
           int x=log10(i)+1;
           if(x%2==0) c++;
        }
        return c;
    }
};