// https://leetcode.com/problems/count-the-number-of-consistent-strings

class Solution {
public:
    int countConsistentStrings(string al, vector<string>& words) {
        set<char>st(al.begin(),al.end());
        
        int c=0;
        for(auto&i:words){
            int f=0;
            for(auto&j:i)
                if(!st.count(j)){f=1;break;}
            if(!f)c++;
        }
        return c;
    }
};