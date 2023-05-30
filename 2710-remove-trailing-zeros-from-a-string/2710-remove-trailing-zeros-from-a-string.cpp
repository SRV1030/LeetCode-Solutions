class Solution {
public:
    string removeTrailingZeros(string num) {
        int i=size(num);
        while(i--){
            if(num[i]!='0') break;
        }
        return num.substr(0,i+1);
    }
};