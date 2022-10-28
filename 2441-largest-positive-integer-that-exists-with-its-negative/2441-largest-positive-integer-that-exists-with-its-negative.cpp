class Solution {
public:
    int findMaxK(vector<int>& nums) {
        vector<int>v(1001);
        int mx=-1;
        for(auto&i:nums){
            if(!v[abs(i)])v[abs(i)]=i;
            else if(v[abs(i)]==(-i)) mx=max(mx,abs(i));
        }
        return mx;
    }
};