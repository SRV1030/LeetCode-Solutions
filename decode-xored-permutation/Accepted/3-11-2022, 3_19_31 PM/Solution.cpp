// https://leetcode.com/problems/decode-xored-permutation

class Solution {
public:
    vector<int> decode(vector<int>& en) {
        int f=0,n=en.size()+1;
        for(int i=0;i<=n;i++){
            f^=i;
            if(i<n && i%2==1)f^=en[i];
        }
        vector<int> ans={f};
        for(auto&i:en){
            ans.push_back(ans.back()^i);
        }
        return ans;
    }
};