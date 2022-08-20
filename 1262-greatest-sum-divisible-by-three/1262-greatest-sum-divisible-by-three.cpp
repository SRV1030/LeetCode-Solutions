class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int>v(3);
        for(auto&i:nums)
            for(int j:vector<int>(v))
                v[(i+j)%3]=max(v[(i+j)%3],i+j);
         return v[0];
    }
};