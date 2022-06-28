class Solution {
public:
    int maximumXOR(vector<int>& nums) {
        int o=0;
        for(auto&i:nums)o|=i;
        return o;
    }
};