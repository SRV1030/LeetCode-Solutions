// https://leetcode.com/problems/peak-index-in-a-mountain-array

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
       int p=0,l=0,r=a.size()-1;        
        while(l<r){
            p = l+(r-l)/2;
            if(a[p]>a[p-1]&&a[p]>a[p+1]) return p;
            else if(a[p]<a[p+1]) l=p;
            else r=p;
        }
        return -1;
    }
};