// https://leetcode.com/problems/number-of-operations-to-make-network-connected

class Solution {
public:
    vector<int> parent;
    int get_parent(int i){
        if(i==parent[i]) return i;
        return parent[i]=get_parent(parent[i]);
    }
    void get_union(int i,int j){
        parent[get_parent(i)]=get_parent(j);
        
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()< n-1) return -1;
        for(int i=0;i<n;parent.emplace_back(i++));
        for(auto&c:connections)get_union(c[0],c[1]);
        int differentComponents= 0;
        for(int i=0;i<n;i++)
            if(parent[i]==i) differentComponents++; 
        return differentComponents-1;
    }
};