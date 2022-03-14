// https://leetcode.com/problems/reverse-prefix-of-word

class Solution {
public:
    string reversePrefix(string word, char ch) {
        auto i=find(word.begin(),word.end(),ch);
        if(i==word.end()) return word;
        int s=0,j=i-word.begin();
        while(s<j)swap(word[s++],word[j--]);
        return word;
    }
};