class Solution {
public:
    bool isP[2000][2000] = {};
    bool checkPartitioning(string s) {
        for (int i = s.size() - 1; i >= 0; --i) {
            for (int j = i; j < s.size(); ++j)
                isP[i][j] = s[i] == s[j] ? i + 1 >= j || isP[i + 1][j - 1] : false;
        }
        for (auto i = 2; i < s.size(); ++i) {
            if (isP[i][s.size() - 1]) {
                for (auto j = 1; j < i; ++j)
                    if (isP[j][i - 1] && isP[0][j - 1])
                        return true;
            }
        }
        return false;
    }
};