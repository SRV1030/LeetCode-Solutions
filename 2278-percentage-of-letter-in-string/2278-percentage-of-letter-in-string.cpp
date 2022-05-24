class Solution {
public:
    int percentageLetter(string s, char letter) {
        int f=0;
        for(auto&i:s)if(i==letter)f++;
        return (f*100)/s.size();
    }
};