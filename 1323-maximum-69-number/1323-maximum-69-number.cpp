class Solution {
public:
    int maximum69Number (int num) {
        string s= to_string(num);
        int i=0,j=size(s)-1;
        for(;i<=j && s[i]!='6';++i);       
        if(i>j) return stoi(s);
        s[i]='9';
        return stoi(s);
    }
};