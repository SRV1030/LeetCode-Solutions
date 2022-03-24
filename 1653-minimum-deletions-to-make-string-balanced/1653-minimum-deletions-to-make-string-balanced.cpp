class Solution {
public:
    int minimumDeletions(string s) {
        int a = count(begin(s), end(s), 'a'), b = 0, res = a;
            for (auto ch : s) {
                b += ch == 'b';
                a -= ch == 'a';
                res = min(res, b + a);
            }
            return res;
    }
};