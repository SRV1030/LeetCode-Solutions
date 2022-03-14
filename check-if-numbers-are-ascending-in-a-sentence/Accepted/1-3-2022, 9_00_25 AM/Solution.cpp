// https://leetcode.com/problems/check-if-numbers-are-ascending-in-a-sentence

class Solution {
public:
    bool areNumbersAscending(string s) {
        s+=" ";
        stringstream str(s);
        string w;
        int pvdg=-1;
        while(str>>w){
            if(isdigit(w[0])){
                int v=stoi(w);
                if(v<=pvdg)return false;
                pvdg=v;                
            }
        }
        return true;
    }
};