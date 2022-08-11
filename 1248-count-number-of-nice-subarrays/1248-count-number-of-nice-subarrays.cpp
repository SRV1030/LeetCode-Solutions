class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int i=0,j=0,o=0,ans=0;
        while(j<size(nums)){
            if(nums[j]%2)++o;
            if(o==k){
                int r=j+1;
                while(r<size(nums) && !(nums[r]%2))++r;
                while(o==k){
                    if(nums[i++]%2)--o;
                    ans+=r-j;
                }
                j=r;
            }
            else ++j;
        }
        return ans;
    }
};