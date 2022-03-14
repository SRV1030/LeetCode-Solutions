// https://leetcode.com/problems/find-the-middle-index-in-array

class Solution {
public:
    int findMiddleIndex(vector<int>& a) {
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