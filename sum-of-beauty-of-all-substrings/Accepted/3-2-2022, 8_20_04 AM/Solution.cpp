// https://leetcode.com/problems/sum-of-beauty-of-all-substrings

class Solution {
public:
    int beautySum(string s) {
        int res=0;
        for(int i=0;i<s.size();i++){            
            vector<int>f(26);
            int mx=0,mn=0;
            for(int j=i;j<s.size();j++){
                int idx=s[j]-'a';
                f[idx]++;
                mx=max(mx,f[idx]);
                if(mn>=f[idx]-1){
                    mn=f[idx];
                    for(auto&i:f)if(i)mn=min(mn,i);
                }
                res+=mx-mn;
            }
        }
        return res;
    }
};