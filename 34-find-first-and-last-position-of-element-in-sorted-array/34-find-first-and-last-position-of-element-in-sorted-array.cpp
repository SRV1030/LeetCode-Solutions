class Solution {
public:
    int binarySearch(vector<int>& nums,int l,int r,int t,bool lbound){
        int res=-1;
        while(l<=r){
            int m=l+(r-l)/2;
            if(nums[m]==t){
                res=m;
                if(lbound)r=m-1;
                else l=m+1;
            }
            else if(nums[m]>t) r=m-1;
            else l=m+1;
        }
        return res;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        if(!n)return{-1,-1};
        int l=binarySearch(nums,0,n-1,target,true);
        if(l==-1) return{-1,-1};
        int r=binarySearch(nums,0,n-1,target,false);
        return {l,r};
    }
};