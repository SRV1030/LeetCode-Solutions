// https://leetcode.com/problems/jewels-and-stones

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        vector<char>f(128);
        for(auto& i:jewels) f[i]++;
        int c=0;
        for(auto&i:stones)if(f[i])c++;
        return c;
    }
};