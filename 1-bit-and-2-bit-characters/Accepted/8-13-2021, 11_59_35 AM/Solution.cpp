// https://leetcode.com/problems/1-bit-and-2-bit-characters

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n=bits.size(); 
        for(int i=0;i<n;i++){
            if(i==n-1) return 1;            
            if(bits[i]==1) i++;
        }
         return 0;
    }
};