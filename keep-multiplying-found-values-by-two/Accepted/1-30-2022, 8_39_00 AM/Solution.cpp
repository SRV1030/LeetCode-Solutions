// https://leetcode.com/problems/keep-multiplying-found-values-by-two

class Solution {
public:
    int findFinalValue(vector<int>& nums, int o) {
        map<int,int>m;
        for(auto x:nums)m[x]++;
        while(true){
            if(m[o]!=0)o=o*2;
            else break;
        }
        return o;
    }
};