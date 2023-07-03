class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        map<int, int> m;
        long long res = 0;
        for (int i = 0, j = 0; i < nums.size(); ++i) {
            auto [it, inserted] = m.insert({nums[i], i});
            if (!inserted)
                it->second = i;
            else {
                for (auto it1 = begin(m); nums[i] - it1->first > 2;) {
                    j = max(j, it1->second + 1);
                    m.erase(it1++);
                }
                for (auto it1 = prev(end(m)); it1->first - nums[i] > 2;) {
                    j = max(j, it1->second + 1);
                    m.erase(it1--);
                }
            }
            res += i - j + 1;
        }
        return res;
    }
};