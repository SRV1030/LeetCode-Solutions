// https://leetcode.com/problems/number-of-wonderful-substrings

long long wonderfulSubstrings(string word) {

	int cnt[1 << 10] = {0};
	int idx = 0;

	long long res = 0;

	for (char& c : word) {

		cnt[idx]++;

		idx ^= (1 << (c - 'a'));

		res += cnt[idx];
		for (int i = 0; i < 10; ++i) {
			res += cnt[idx ^ (1 << i)];
		}

	}

	return res;
}