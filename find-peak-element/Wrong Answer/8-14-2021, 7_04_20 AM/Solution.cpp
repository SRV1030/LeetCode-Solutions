// https://leetcode.com/problems/find-peak-element

class Solution {
public:
    int findPeakElement(vector<int>& a) {
        int p=0,l=0,n=a.size(),r=n-1;        
        if(n==1) return a[0];
        else if(n==2)return max(a[0],a[1]);
        while(l<r){
            p = l+(r-l)/2;
            if(a[p]>a[p-1]&&a[p]>a[p+1]) return p;
            else if(p<n-1 && a[p]<a[p+1]) l=p;
            else r=p;
        }
        return -1;
    }
};