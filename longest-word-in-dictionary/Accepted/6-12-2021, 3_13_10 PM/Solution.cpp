// https://leetcode.com/problems/longest-word-in-dictionary

class Solution {
public:
    string longestWord(vector<string>& words) {
        set<string>s(words.begin(),words.end());
        string res="";
        for(auto& i:s){
            string t="";
            bool f=false;
            for(char j:i){
                t+=j;
                if(s.find(t)==s.end()){
                    f=false;
                    break;
                }
                f=true;                
            }
            if(f){
                if(i.length()>res.length())res=i;
            }
        }
        return res;
    }
};