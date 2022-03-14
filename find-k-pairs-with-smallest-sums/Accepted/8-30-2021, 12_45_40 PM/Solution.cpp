// https://leetcode.com/problems/find-k-pairs-with-smallest-sums

class Solution {
public:
	vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n1=nums1.size(), n2=nums2.size();
        vector<vector<int>> ans;
        using tt = tuple<int, int, int>;
        set<tt> s;
        s.insert({nums1[0]+nums2[0], 0, 0});
        while(!s.empty() && ans.size() < k) {
            auto [v, i1, i2] = *s.begin(); 
            s.erase(s.begin());
            ans.push_back({nums1[i1], nums2[i2]});
            if(i1!=n1-1) s.insert({nums1[i1+1]+nums2[i2], i1+1, i2});
            if(i2!=n2-1) s.insert({nums1[i1]+nums2[i2+1], i1, i2+1});
        }
        return ans;
    }
};