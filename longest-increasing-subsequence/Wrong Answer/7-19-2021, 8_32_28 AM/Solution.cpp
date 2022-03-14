// https://leetcode.com/problems/longest-increasing-subsequence

class Solution {
public:
    int uBound(int v[],int l,int h,int k){
        while(l<h){
            int m=l+(h-l)/2;
            if(v[m]<k) l=m+1;
            else h=m;            
        }
        return h;
    }
    int lengthOfLIS(vector<int>& a) {
        int l=1,n=a.size();
        int dp[n];
        dp[0]=a[0];
        for(int i=1;i<n;i++){
            if(dp[l-1]<=a[i])dp[l++]=a[i];
            else{
                int x=uBound(dp,0,l-1,a[i]);
                dp[x]=a[i];
            }
        }
        return l;
    }
};