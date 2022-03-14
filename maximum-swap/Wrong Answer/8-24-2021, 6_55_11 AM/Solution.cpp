// https://leetcode.com/problems/maximum-swap

class Solution {
public:
    int maximumSwap(int num) {
        string s=to_string(num);
        int n=s.size();
        vector<int>v(n);
        v[n-1]=n-1;
        for(int i=n-2;i>=0;i--)v[i]=s[i]>=s[v[i+1]]?i:v[i+1];
        for(int i=0;i<n;i++)
            if(v[i]!=i){
                swap(s[i],s[v[i]]);
                break;
            }
        return stoi(s);
    }
};