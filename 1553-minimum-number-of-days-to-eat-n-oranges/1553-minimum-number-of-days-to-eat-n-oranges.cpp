class Solution {
public:
    unordered_map<int,int>mp;
    int minDays(int n) {
        if(n<=1)return 1;
        if(mp.count(n))return mp[n];
        return mp[n]=1+min(n%2+minDays(n/2),n%3+minDays(n/3));
    }
};