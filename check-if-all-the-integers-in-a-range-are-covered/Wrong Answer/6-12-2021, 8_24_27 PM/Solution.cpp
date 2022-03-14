// https://leetcode.com/problems/check-if-all-the-integers-in-a-range-are-covered

class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        int f1=0,f2=0;
        for(auto i:ranges){
            if(i[0]<=left && left<=i[1])f1=1;
            if(i[0]<=right && right<=i[1])f2=1;
          if(f1 && f2) return true;  
        }
        return false;
        
    }
};