class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n1=size(nums1),n2=size(nums2);
        int dp[n1+1][n2+1],mx=0;
        for(int i=0;i<=n1;++i)
            for(int j=0;j<=n2;++j){
                if(i==0 || j==0)dp[i][j]=0;
                else{
                    if(nums1[i-1]==nums2[j-1])dp[i][j]=1+dp[i-1][j-1];
                    else dp[i][j]=0;
                }
                mx=max(mx,dp[i][j]);
            }
        return mx;
    }
};