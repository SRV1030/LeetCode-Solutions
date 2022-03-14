// https://leetcode.com/problems/longest-happy-prefix

class Solution {
public:
    string longestPrefix(string s) {
        int n=s.size();
        vector<int>v(n);
        for(int i=1,j=0;i<n;){
            if(s[j]==s[i]){
                v[i]=j+1;
                j++;i++;
            }
            else{
                if(j)j=v[j-1];
                else{
                    v[i]=0;
                    i++;
                }
            }
        }
        int x = n - v[n-1];
        return s.substr(x);
    }
};