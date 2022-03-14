// https://leetcode.com/problems/snapshot-array

class SnapshotArray {
public:
    unordered_map<int,vector<int>>mp;
    int sn=0,l;
    
    SnapshotArray(int length) {
        l=length;
    }
    
    void set(int index, int val) {
        if(!mp.count(index))mp[index]=vector<int>(l);
        mp[index][sn]=val;
        // cout<<index<<" "<<sn<<" "<<mp[index][sn]<< "\n";
    }
    
    int snap() {
        sn++;
        return sn-1;
    }
    
    int get(int index, int snap_id) {
        // cout<<mp[0][0]<<" ";
        return mp[index][snap_id];
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */