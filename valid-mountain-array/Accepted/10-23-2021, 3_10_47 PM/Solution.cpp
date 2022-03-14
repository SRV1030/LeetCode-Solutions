// https://leetcode.com/problems/valid-mountain-array

class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int i=0,n=arr.size()-1;
        while(i<n && arr[i]<arr[i+1])i++;
        if(i==0 || i==n) return false;
        while(i<n && arr[i]>arr[i+1])i++;
        return i==n;
    }
};