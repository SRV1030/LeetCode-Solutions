// https://leetcode.com/problems/minimize-maximum-pair-sum-in-array

class Solution {
public:
    int minPairSum(vector<int>& a) {
        
        sort(a.begin(), a.end()); 
        int i=0,j=a.size()-1;
        int mx=INT_MIN;
        while(i<j){
            mx=max(mx,a[i++]+a[j--]);
        }
        return mx;
        
    }
};