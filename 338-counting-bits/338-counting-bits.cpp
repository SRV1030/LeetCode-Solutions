class Solution {
public:
    vector<int> countBits(int n) {
       vector<int> v(n+1);
        for(int i=1;i<=n;i++) v[i]=i%2?1+v[i>>1]:v[i>>1];
        return v;
    }
};