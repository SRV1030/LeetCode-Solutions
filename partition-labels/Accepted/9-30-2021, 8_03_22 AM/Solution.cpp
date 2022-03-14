// https://leetcode.com/problems/partition-labels

class Solution {
public:
    vector<int> partitionLabels(string s) {
      vector<int> locur(26),ans;
      for(int i=0;i<s.size();i++)locur[s[i]-'a']=i;
      int b=0;
      for(int i=0,j=0;i<s.size();i++){
          j=max(j,locur[s[i]-'a']);
          if(i==j){
              ans.push_back(j-b+1);
              b=i+1;
          }
      }
      return ans;
    }
};