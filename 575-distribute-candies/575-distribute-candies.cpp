class Solution {
public:
    int distributeCandies(vector<int>& c) {
        set<int>s(begin(c),end(c));
        return min(size(s),size(c)/2);
    }
};