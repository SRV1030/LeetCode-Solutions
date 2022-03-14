// https://leetcode.com/problems/range-module

class RangeModule {
public: map<int,int>mp;
    RangeModule() {
        
    }
    
    void addRange(int left, int right) {
        auto it=mp.lower_bound(left),nxt=it;
        while(nxt!=mp.end() && nxt->second<=right){
            left=min(left,nxt->second);
            right=max(right,nxt->first);
            nxt++;
        }
        mp.erase(it,nxt);
        mp[right]=left;
    }
    
    bool queryRange(int left, int right) {
        auto it=mp.lower_bound(left);
        if(it==mp.end()) return false;
        return it->second<=left && it->first>= right;
    }
    
    void removeRange(int left, int right) {
        auto it=mp.lower_bound(left),nxt=it;
        if(it==mp.end()) return;
        vector<pair<int,int>> dRanges;
        while(nxt!=mp.end() && nxt->second<right){
            if(nxt->second<left)dRanges.push_back({nxt->second,left});
            if(nxt->first>right)dRanges.push_back({right,nxt->first});
            nxt++;
        }
        mp.erase(it,nxt);
        for(auto& i:dRanges)mp[i.second]=i.first;
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */