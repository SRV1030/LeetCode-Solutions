class Solution {
public:
    bool isFascinating(int n) {
        string s= to_string(n)+to_string(2*n)+to_string(3*n);
        sort(begin(s),end(s));
        return s=="123456789";
    }
};