class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string s1,s2;
        for(auto&i:word1)s1+=i;
        for(auto&j:word2)s2+=j;
        return s2==s1;            
    }
};