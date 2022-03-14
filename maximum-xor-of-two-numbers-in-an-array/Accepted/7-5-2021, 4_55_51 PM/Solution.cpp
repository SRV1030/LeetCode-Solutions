// https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int n = nums.size();

		int ans = 0, mask = 0;
		for (int i = 31; i >= 0; --i) {
			mask = mask | (1 << i);
			int greedyAns = (ans | (1 << i));
			unordered_set<int> s;
			for (auto &num : nums) {
				//We basically insert with first i bits conserved and the rest of the bits are 0 after i
				s.insert(num & mask);
			}

			for (auto &prefix : s) {
				if (s.find(greedyAns ^ prefix) != s.end()) {
					ans = greedyAns;
					break;
				}
			}
		}

		return ans;
    }
};