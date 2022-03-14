// https://leetcode.com/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold

class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int t) {
        double s=0,avg;
        int c=0,n=arr.size();
        for(int i=0;i<k;i++)s+=arr[i];
        avg=s/((double)k);
        if(avg>=(double)t)c++;
        for(int i=1;i<n-k+1;i++){
            s-=arr[i-1];
            s+=arr[i+k-1];
            avg=s/((double)k);
            if(avg>=(double)t)c++;
        }
        return c;
    }
};