class Solution {
public:
int fillCups(vector<int>& a) {
    return max(max({a[0], a[1], a[2]}), (a[0] + a[1] + a[2] + 1) / 2);
}

};