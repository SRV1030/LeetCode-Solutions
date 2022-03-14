// https://leetcode.com/problems/longest-common-prefix

class Solution {
    
public:
    int Min(int a,int b){
        if(a<b)return a;
        else return b;
    }
     string longestCommonPrefix(vector<string>& s) {
        string op="";
        
        int n=s.size();
        int m=2000;
        int c=0;
        for(int i=0;i<s.size();i++){
            m=Min(m,s[i].size());
        }
         // cout<<m<<" "<<n;
         int i=0,j=0;
         for(j=0;j<m;j++){
             c=0;
             for(i=0;i<n-1;i++){
                 if(s[i][j]==s[i+1][j]) c++; 
                 else break;
             }
             if(c==n-1)op+=s[0][j];
             else break;
         }
        return op;
    }
};