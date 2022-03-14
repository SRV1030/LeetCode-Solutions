// https://leetcode.com/problems/excel-sheet-column-number

class Solution {
public:
    int titleToNumber(string columnTitle) {
        int v=0;
        for(auto&i:columnTitle){
            v*=26;
            v+=(i-'A'+1);
        }
        return v;
    }
};