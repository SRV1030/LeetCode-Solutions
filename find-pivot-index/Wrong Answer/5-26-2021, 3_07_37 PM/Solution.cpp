// https://leetcode.com/problems/find-pivot-index

class Solution {
public:
    int pivotIndex(vector<int>& a) {
        int l=0,n=a.size();
        int r=accumulate(a.begin() , a.end() , 0);
        if(l==r) return 0;
        for(int i=1;i<n;i++){            
            l+=a[i-1];
            r-=a[i];
            if(l==r) return i;
        }
        return -1;      
        
    }
};