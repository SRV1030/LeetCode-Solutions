// https://leetcode.com/problems/trapping-rain-water

// class Solution {
// public:
//     int trap(vector<int>& h) {
//         int n=h.size();
//         if(n==0) return 0;
//         int l[n],r[n],ans=0;
//         l[0]=h[0];
//         r[n-1]=h[n-1];
//         for(int i=1;i<n;i++)l[i]=max(h[i],l[i-1]);
//         for(int i=n-2;i>=0;i--)r[i]=max(h[i],r[i+1]);
//         for(int i=0;i<n;i++)ans+=min(l[i],r[i])-h[i];
//         return ans;
//     }
// };


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