// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array

class Solution {
public:
    int findMin(vector<int>& a) {
        int s=a.size();
        if(s==1) return a[0];
        if(a[s-1]>a[0]) return a[0];
        int l=0,r=s-1;
        while(r>=l){
            int m=l+(r-l)/2;
            if(m-1>=0 && a[m-1]>a[m]) return a[m];
            if(m+1<s && a[m]>a[m+1]) return a[m+1];
            if(a[m]>a[0])l=m+1;
            else r=m-1;
        }
        return -1;
    }
};