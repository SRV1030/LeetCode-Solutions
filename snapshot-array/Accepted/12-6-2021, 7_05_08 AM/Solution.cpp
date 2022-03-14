// https://leetcode.com/problems/snapshot-array

class SnapshotArray {
public:
	int snapId;
	vector<vector<pair<int, int>> *> map;

	SnapshotArray(int length) : snapId(0), map(length) {}

	void set(int index, int val) {
		auto* v = map[index];
		if (v == NULL)
			map[index] = new vector<pair<int, int>>(1, make_pair(snapId, val));
		else if (v->back().first < snapId)
			v->emplace_back(make_pair(snapId, val));
		else
			v->back().second = val;
	}
	// snap_id for getting is different from setting. They have a difference of 1.
	int snap() { return snapId++; }

	int get(int index, int snap_id) {
		auto* v = map[index];
		if (v == NULL)
			return 0;	// not been set, return default value;
		// find the snap_id using binary search
		auto it = lower_bound(v->begin(), v->end(), make_pair(snap_id, 0), 
			[](const auto& l, const auto& r) { return (l.first < r.first); } );
		if (it == v->end())
			return v->back().second;	// latest
		if (it->first == snap_id)
			return it->second;			// snap_id is found.
		if (it == v->begin())			
			return 0;					// snap_id < 1st, it's default
		return (--it)->second;			// "it" is just bigger than snap_id, previous one is the result
	}
};
