// https://leetcode.com/problems/excel-sheet-column-title

class Solution {
public:
    string convertToTitle(int c) {
        string s="";
        while(c){
            int x=(c-1)%26;
            s+=(char)('A'+x);
            c=(c-1)/26;
        }
        return s;
    }
}; 