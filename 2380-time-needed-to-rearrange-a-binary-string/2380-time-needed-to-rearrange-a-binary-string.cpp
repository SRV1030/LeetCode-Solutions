class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        int c=0,z=0;
        for(auto&i:s){
            z+=i=='0';
            if(i=='1' && z)c=max(c+1,z);
        }
        return c;
    }
};