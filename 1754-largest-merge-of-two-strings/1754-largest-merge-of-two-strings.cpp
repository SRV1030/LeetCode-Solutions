class Solution {
public:
string largestMerge(string w1, string w2) {
    string res;
    int i = 0, j = 0;
    while(i < w1.size() && j < w2.size()) {
        if (w1.compare(i, w1.size() - i, w2, j, w2.size() - j) > 0)
            res += w1[i++];
        else
            res += w2[j++];
    }
    return res + w1.substr(i) + w2.substr(j);
}
};