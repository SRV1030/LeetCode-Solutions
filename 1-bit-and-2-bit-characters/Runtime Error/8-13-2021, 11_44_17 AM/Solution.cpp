// https://leetcode.com/problems/1-bit-and-2-bit-characters

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n=bits.size();
        for(int i=0;i<n-1;i+=2){
            if(bits[i]==0) i--;
            if(bits[i]==1 && i+1<n-1)continue;
            else return 0;
        }
         return 1;
    }
};