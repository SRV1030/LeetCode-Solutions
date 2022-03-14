// https://leetcode.com/problems/find-missing-observations

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        long long s=0;
        for(auto&i:rolls)s+=i;
        s=mean*(n+rolls.size())-s;
        if(s<=0 || s>6*n) return{};
        vector<int> v(n);
        int x=s/n;
        for(int i=0;i<n-1;i++){
            v[i]=x;
            s-=x;
        }
        v[n-1]=s;
        return v;
    }
};