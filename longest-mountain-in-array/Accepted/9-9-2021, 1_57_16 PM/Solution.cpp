// https://leetcode.com/problems/longest-mountain-in-array

class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int mx=0,n=arr.size();
        if(n==1) return 0;
        for(int i=1;i<n-1;i++){
            int l=i,r=i;
            while(l-1>=0 && arr[l]>arr[l-1])l--;
            if(l==i)continue;
            while(r+1<n && arr[r]>arr[r+1])r++;
            if(r!=i && r-l+1>mx)mx=r-l+1;
        }
        return mx==1?0:mx;
    }
};