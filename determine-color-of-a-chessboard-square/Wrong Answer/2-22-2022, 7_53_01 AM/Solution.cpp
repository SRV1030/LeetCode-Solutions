// https://leetcode.com/problems/determine-color-of-a-chessboard-square

class Solution {
public:
    bool squareIsWhite(string cd) {
        return (cd[0]+cd[1])%2==0;
    }
};