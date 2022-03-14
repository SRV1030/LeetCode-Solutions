// https://leetcode.com/problems/check-if-all-the-integers-in-a-range-are-covered

class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        int f1=0;
        for(int i=left;i<=right;i++){
            f1=0;
           for(auto j:ranges){
               if(j[0]<=i && i<=j[1]) {
                   f1=1;
                   break;
               }               
           }
        if(!f1) return false;
        }
        return true;
        
    }
};