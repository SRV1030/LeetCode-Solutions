// https://leetcode.com/problems/all-oone-data-structure

class AllOne {
public: map<int,set<string>>count;
        unordered_map<string,int>mp;
    /** Initialize your data structure here. */
    AllOne() {
        
    }
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
            mp[key]++;
            count[mp[key]].insert(key);
            if(mp[key]>1){
                count[mp[key]-1].erase(key);
                if(count[mp[key]-1].empty())count.erase(mp[key]-1);
            }
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        mp[key]--;
        count[mp[key]+1].erase(key);
        if(count[mp[key]+1].empty())count.erase(mp[key]+1);
        if(mp[key]==0)mp.erase(key);
        else count[mp[key]].insert(key);
    }
    
    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        if(count.empty())return "";
        auto it=count.end();
        it--;
        return *it->second.begin();
    }
    
    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        if(count.empty())return "";
        auto it=count.begin();
        return *it->second.begin();
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */