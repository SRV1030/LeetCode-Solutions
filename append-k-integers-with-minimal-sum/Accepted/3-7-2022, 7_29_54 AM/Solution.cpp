// https://leetcode.com/problems/append-k-integers-with-minimal-sum

class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        long long res=(long long)k*(k+1)/2;
        for(auto& i:set<int>(nums.begin(),nums.end()))
            if(i<=k){
                res+=(++k)-i;
            }
        return res;
    }
};