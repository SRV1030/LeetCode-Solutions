// https://leetcode.com/problems/find-the-distance-value-between-two-arrays

class Solution {
public:
    int bsearch(vector<int>&arr,int k){
        int l=0,r=arr.size()-1;
        while(l<=r){
            int m=(l+r)>>1;
            if(arr[m]>=k) r=m-1;
            else l=m+1;
        }
        return l;
    }
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int c=0;
        for(auto& i:arr1){
            int ind=bsearch(arr2,i-d);
            if(ind==arr2.size() || arr2[ind]>i+d)c++;
        }
        return c;
    }
};