class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int x=-1,y=-1;
        for(auto&i:nums){
            if(i>x)y=x,x=i;
            else if(i>y)y=i;
        }
        return (x-1)*(y-1);
    }
};