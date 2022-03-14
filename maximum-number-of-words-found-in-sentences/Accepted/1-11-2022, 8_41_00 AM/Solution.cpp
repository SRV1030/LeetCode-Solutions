// https://leetcode.com/problems/maximum-number-of-words-found-in-sentences

class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int mx=0;
        for(auto&i:sentences){
            stringstream str(i);
            string w;
            int c=0;
            while(str>>w)c++;
            if(c>mx)mx=c;
        }
        return mx;
    }
};