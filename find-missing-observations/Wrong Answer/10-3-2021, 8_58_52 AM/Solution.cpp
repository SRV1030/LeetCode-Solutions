// https://leetcode.com/problems/find-missing-observations

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        long long s=0;
        for(auto&i:rolls)s+=i;
        s=mean*(n+rolls.size())-s;
        if(s<=n || s>6*n) return{};
        vector<int> v(n);
        int f=s/n,c=(s+n-1)/n;
        for(int i=0;i<n;i++){
            if(s==(n-i)*f){
                v[i]=f;
                s-=f;
            }else{
                v[i]=c;
                s-=c;
            }
        }
        return v;
    }
};