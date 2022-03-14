// https://leetcode.com/problems/trapping-rain-water

class Solution {
public:
    int trap(vector<int>& h) {
        int l=0,r=h.size()-1,ans=0,lmx=0,rmx=0;
        while(l<=r){
            if(h[l]<=h[r]){
                if(h[l]<lmx)ans+=lmx-h[l];
                else lmx=h[l];
                l++;
            }
            else{
               if(h[r]<rmx)ans+=rmx-h[r];
                else rmx=h[r];
                r--; 
            }
        }
        return ans;
    }
};