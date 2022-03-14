// https://leetcode.com/problems/longest-mountain-in-array

class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int mx=0,n=arr.size();
        for(int i=0;i<n;i++){
            int l=i,r=i;
            while(l-1>=0 && arr[l]>arr[l-1])l--;
            while(r+1<n && arr[r]>arr[r+1])r++;
            if(r-l+1>mx)mx=r-l+1;
            // cout<<l<<" "<<i<<" "<<r<<"\n";
            if(mx==n) return mx;
        }
        return mx==1?0:mx;
    }
};