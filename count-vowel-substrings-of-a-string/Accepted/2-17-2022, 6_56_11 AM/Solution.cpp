// https://leetcode.com/problems/count-vowel-substrings-of-a-string

class Solution {
public:
    int countVowelSubstrings(string word) {
        int n = word.size(), ans = 0;
        unordered_set<char> vowels{'a', 'e', 'i', 'o', 'u'};
        for(int i = 0; i < n; i++){
            for(int j = 1; j <= n - i; j++){
                string s = word.substr(i, j);
                unordered_set<char> str(begin(s), end(s));
                if(str == vowels) ans++;
            }
        }
        return ans;
    }
};