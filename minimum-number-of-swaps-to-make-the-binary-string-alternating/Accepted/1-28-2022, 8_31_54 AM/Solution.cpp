// https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-binary-string-alternating

class Solution {
public:
    int minSwaps(string s) {
        int cz=0,odz=0,evz=0,n=s.size();
        for(int i=0;i<s.size();i++)
            if(s[i]=='0'){
                cz++;
                if(i&1)odz++;
                else evz++;
            }
        if(n%2==0){
            if(cz!=n/2) return-1;
            return min(cz-odz,cz-evz);
        }
        else{
            if(cz==n/2) return cz-odz;
            else if(cz==(n/2+1)) return n/2+1-evz;
            return -1;
        }
        
    }
};