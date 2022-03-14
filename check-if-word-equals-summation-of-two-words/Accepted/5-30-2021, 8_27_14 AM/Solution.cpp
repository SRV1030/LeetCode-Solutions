// https://leetcode.com/problems/check-if-word-equals-summation-of-two-words

class Solution {
public:
    bool isSumEqual(string f, string s, string t) {
        string s1="",s2="",s3="";
        for(auto i:f){
            int x=(i-'a');
            s1+=to_string(x);
        }
        for(auto i:s){
            int x=(i-'a');
            s2+=to_string(x);
        }
        for(auto i:t){
            int x=(i-'a');
            s3+=to_string(x);
        }
        return stoi(s3)==stoi(s1)+stoi(s2);
        
        
    }
};