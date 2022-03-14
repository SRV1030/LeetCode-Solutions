// https://leetcode.com/problems/find-peak-element

class Solution {
public:
    int findPeakElement(vector<int>& a) {
        int p=0,l=0,n=a.size(),r=n-1;        
        if(n==1) return 0;
        else if(n==2)return a[0]>a[1]?0:1;
        else if(a[0]>a[1]) return 0;
        else if(a[n-1]>a[n-2]) return n-2;
        while(l<r){
            p = l+(r-l)/2;
            if(p-1>=0 && p+1<=n-1 && a[p]>a[p-1]&&a[p]>a[p+1]) return p;
            else if(p<n-1 && a[p]<a[p+1]) l=p+1;
            else r=p-1;
        }
        return -1;
    }
};