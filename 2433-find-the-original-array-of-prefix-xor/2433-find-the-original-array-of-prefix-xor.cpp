class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        vector<int> ans(size(pref));
        ans[0]=pref[0];
        for(int i=1;i<size(pref);++i)ans[i]=pref[i]^pref[i-1];
        return ans;
    }
};