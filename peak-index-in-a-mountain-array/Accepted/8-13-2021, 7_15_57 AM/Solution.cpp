// https://leetcode.com/problems/peak-index-in-a-mountain-array

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n=arr.size();
        
        for(int i=1;i<n-1;i++){
            int l=i-1,r=i+1;
            bool f1=false,f2=false;
            while(l>=0){
                if(arr[l]>arr[i]){
                    f1=true;
                    break;
                }
                l--;
            }
            while(r<n){
                if(arr[r]>arr[i]){
                    f2=true;
                    break;
                }
                r++;
            }
            if(!f1&&!f2) return i;
        }
        return -1;
    }
};