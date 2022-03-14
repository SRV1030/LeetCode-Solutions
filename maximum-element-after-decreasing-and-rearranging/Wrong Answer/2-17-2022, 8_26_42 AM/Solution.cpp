// https://leetcode.com/problems/maximum-element-after-decreasing-and-rearranging

class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n=arr.size();
        vector<int>v;
        for(int i=1;i<=n;v.emplace_back(i++));
        sort(arr.begin(),arr.end());
        if(arr[n-1]==1) return 1;
        for(int i=0;i<n;i++)if(arr[i]!=1 && arr[i]<v[i]) return arr[i];
        return min(arr[n-1],n);
    }
};