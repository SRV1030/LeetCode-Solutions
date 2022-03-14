// https://leetcode.com/problems/minimum-cost-to-move-chips-to-the-same-position

class Solution {
public:
    int minCostToMoveChips(vector<int>& p) {
        int o=0,e=0;
        for(auto& i:p){
            if(i&1)o++;
            else e++;
        }
        return min(o,e);
    }
};