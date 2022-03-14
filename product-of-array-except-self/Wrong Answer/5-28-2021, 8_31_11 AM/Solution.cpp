// https://leetcode.com/problems/product-of-array-except-self

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& a) {
        long long int p=1,z=1;
        vector<int> ans;
        for(auto i:a){
            p*=i;
            if(i)z*=i;
        }
        if(!p){
              for(auto i:a){
                  if(i)ans.push_back(0);
                  else ans.push_back(z);
              }   
            return ans;
        }
        for(auto i:a)ans.push_back(p/i);
        return ans;
    }
};