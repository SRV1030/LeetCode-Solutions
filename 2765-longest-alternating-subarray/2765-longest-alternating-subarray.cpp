class Solution {
public:
    int alternatingSubarray(vector<int>& nums) {
        int mx=-1,c=INT_MAX;
        for(int r=1,l=0;r<size(nums);++r){
            int d=nums[r]-nums[r-1];
            if(d==c*(-1)){
                c*=-1;
                mx=max(mx,r-l+1);
            }
            else{
                if(d==1){
                    c=1;
                    l=r-1;
                    mx=max(mx,r-l+1);
                }
                else c=INT_MAX;
            }
        }
        return mx;
    }
};