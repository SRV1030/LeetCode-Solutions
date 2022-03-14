// https://leetcode.com/problems/maximum-binary-string-after-change

class Solution {
public:
    string maximumBinaryString(string b) {
        int n=b.size(),prev=0;
        while(prev<n && b[prev]=='1')prev++;
        if(prev==n) return b;
        int z=0;
        for(auto&i:b)z+=(i=='0');
        string ans(n,'1');
        ans[prev+z-1]='0';
        return ans;
    }
};