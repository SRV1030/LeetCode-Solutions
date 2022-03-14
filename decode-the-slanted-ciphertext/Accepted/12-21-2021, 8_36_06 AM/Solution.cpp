// https://leetcode.com/problems/decode-the-slanted-ciphertext


class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        string ans;
        int col= encodedText.size()/rows;
        for(int j=0;j<col;j++){
            for(int k=j; k<encodedText.size();k+=col+1)ans+=encodedText[k];
        }
        ans.erase(ans.find_last_not_of(" \n\r\t")+1);
        return ans;
    }
};