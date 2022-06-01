class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int z=-1,mx=0,neg=-1,c=0;
        for(int i=0;i<size(nums);++i){
            if(nums[i]<0 && neg==-1)neg=i;
            if(nums[i]<0)c++;
            if(!nums[i]){
                z=i;
                neg=-1;
                c=0;
            }
            else  mx=c%2?max(mx,i-neg):max(mx,i-z);
        }
        return mx;
    }
};