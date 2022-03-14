// https://leetcode.com/problems/last-substring-in-lexicographical-order

class Solution {
public:
    string lastSubstring(string s) {
      char mx=s[0];
      int mi=0,n=s.length();
      for(int i=0;i<n;i++){
          if(s[i]>mx){
              mx=s[i];
              mi=i;
          }
          else if(s[i]==mx){
              int j=1;
              while(s[i+j]==s[mi+j] && j+mi<i)j++;
              if(s[i+j]>s[mi+j])mi=i;
              i=i+j-1;
          }
      }
      return s.substr(mi,n-mi+1);        
    }
};
