// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array

class Solution {
public:
    int findMin(vector<int>& a) {
        int s=a.size();
        if(s==0) return a[0];
        else if(a[s-1]>a[0]) return a[0];
        else{
            for(int i=1;i<s;i++){
                if(a[i-1]>a[i]) return a[i];
            }
            return 0;
        }
    }
};