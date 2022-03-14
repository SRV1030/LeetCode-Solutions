// https://leetcode.com/problems/maximum-product-subarray

class Solution {
public:
    int maxProduct(vector<int>& arr) {
        long long mxf=arr[0],mxs=arr[0],mns=arr[0],n=arr.size();
	    for(int i=1;i<n;i++){
	        int t=mxs;
	        mxs=max((long long)arr[i],max((long long)mxs*arr[i],(long long)mns*arr[i]));
	        mns=min((long long)arr[i],min((long long)t*arr[i],(long long)mns*arr[i]));
	        if(mxs>mxf)mxf=mxs;
	    }
	    return mxf;
    }
};