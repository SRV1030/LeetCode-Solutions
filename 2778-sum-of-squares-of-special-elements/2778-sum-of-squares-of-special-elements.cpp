class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int ans=0,n=size(nums);
        for(int i=1;i*i<=n;++i)
            if(n%i==0){
                ans+=nums[i-1]*nums[i-1];
                if((n/i)!=i)ans+=nums[n/i-1]*nums[n/i-1];
            }
                
        return ans;
    }
};