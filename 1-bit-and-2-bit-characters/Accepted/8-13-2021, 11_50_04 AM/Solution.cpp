// https://leetcode.com/problems/1-bit-and-2-bit-characters

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        short n=bits.size();
        short i=n-2;
        while(i>=0 && bits[i]) i--;
        return !((n-2-i)&1);
    }
};