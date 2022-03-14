// https://leetcode.com/problems/compare-strings-by-frequency-of-the-smallest-character

class Solution {
public:
    int getf(string s){
        int mn=1;
        char mnc='}';
        for(auto&i:s){
            if(i==mnc)mn++;
            else if(i<mnc){
                mnc=i;
                mn=1;
            }
        }
        return mn;
    }
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> res,w;
        for(auto&i:words)w.push_back(getf(i));
        for(auto&i:queries){
            int c=0,x=getf(i);
            for(auto&j:w)if(x<j)c++;
            res.push_back(c);
        }
        return res;
    }
};