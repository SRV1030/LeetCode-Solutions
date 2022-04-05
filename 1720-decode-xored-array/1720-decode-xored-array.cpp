class Solution {
public:
    vector<int> decode(vector<int>& encoded, int f) {
        vector<int>ans={f};
        for(auto&i:encoded)ans.push_back(ans.back()^i);
        return ans;
    }
};