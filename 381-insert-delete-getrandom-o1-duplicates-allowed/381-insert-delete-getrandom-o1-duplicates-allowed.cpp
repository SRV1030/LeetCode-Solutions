class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    unordered_map<int,unordered_set<int>>mp;
    vector<int>v;
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        v.emplace_back(val);
        mp[val].insert(size(v)-1);
        return mp[val].size()==1;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        auto it=mp.find(val);
        if(it!=mp.end()){
            auto rem_idx=*it->second.begin();
            it->second.erase(it->second.begin());
            v[rem_idx]=v.back();
            mp[v.back()].insert(rem_idx);
            mp[v.back()].erase(size(v)-1);
            v.pop_back();
            if(!size(it->second))mp.erase(it);
            return true;
        }
        return false;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return v[rand()%size(v)];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */