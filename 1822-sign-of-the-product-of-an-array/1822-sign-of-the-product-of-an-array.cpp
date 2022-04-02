class Solution {
public:
    int arraySign(vector<int>& nums) {
        int sg=1;
        for(auto&i:nums){
            if(!i) return 0;
            if(i<0)sg=-sg;
        }
        return sg;
    }
};