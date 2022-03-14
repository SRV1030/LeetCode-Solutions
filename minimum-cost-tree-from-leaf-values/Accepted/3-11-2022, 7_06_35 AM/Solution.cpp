// https://leetcode.com/problems/minimum-cost-tree-from-leaf-values

class Solution {
public:
  int mctFromLeafValues(vector<int>& arr) {
       int mns=0;
      while(arr.size()>1){
          int mnp=INT_MAX,idx=-1;
          for(int i=0;i<arr.size()-1;i++){
              if(arr[i]*arr[i+1]<mnp){
                  mnp=arr[i]*arr[i+1];
                  idx=arr[i]<arr[i+1]?i:i+1;
              }
          }
          mns+=mnp;
          arr.erase(arr.begin()+idx);
      }
      return mns;
    }
};