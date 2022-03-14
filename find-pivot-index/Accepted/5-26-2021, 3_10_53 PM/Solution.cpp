// https://leetcode.com/problems/find-pivot-index

class Solution {
public:
    int pivotIndex(vector<int>& a) {
        int l=0,n=a.size();
        int r=accumulate(a.begin() , a.end() , 0);
        for(int i=0;i<n;i++){
            r-=a[i];
            if(l==r) return i;
             l+=a[i];
        }
        return -1;      
        
    }
};