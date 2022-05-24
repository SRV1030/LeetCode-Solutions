class Solution {
public:
    int percentageLetter(string s, char letter) {        
        return (count(begin(s),end(s),letter)*100)/s.size();
    }
};