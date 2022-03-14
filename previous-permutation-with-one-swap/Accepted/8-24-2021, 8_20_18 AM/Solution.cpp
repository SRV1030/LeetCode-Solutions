// https://leetcode.com/problems/previous-permutation-with-one-swap

class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        int n=arr.size();
        int x=-1,y=-1;
        for(int i=n-1;i>0;i--){
            if(arr[i-1]>arr[i]){
                x=i-1;
                break;
            }
        }
        if(x==-1) return arr;  
        // cout<<x<<" ";
        for(int j=x+1;j<n;j++){
            if(arr[j]<arr[x]){
                if(y==-1)y=j;
                else if(arr[j]>arr[y])y=j;
            }
        }
        swap(arr[x],arr[y]);
        return arr;
    }
};