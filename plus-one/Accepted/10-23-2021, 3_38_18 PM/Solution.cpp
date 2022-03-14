// https://leetcode.com/problems/plus-one

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int c=1;
        for(int i=digits.size()-1;i>=0;i--){
            c+=digits[i];
            digits[i]=c%10;
            c=c/10;
        }
        if(c)digits.insert(digits.begin(),c);
        return digits;
    }
};