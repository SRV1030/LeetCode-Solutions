class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int>v(3);
        for(auto&i:nums){
            vector<int>t=v;
            for(auto&j:t)
                v[(i+j)%3]=max(v[(i+j)%3],i+j);                        
        }
        return v[0];
    }
};

//Basically remove the least additive