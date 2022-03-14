// https://leetcode.com/problems/redundant-connection

class Solution {
public:
    vector<int>parent;
    int get_parent(int i){
        if(i==parent[i]) return i;
        return parent[i]=get_parent(parent[i]);
    }
    void get_union(int i,int j){
        parent[get_parent(i)]=get_parent(j);
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        for(int i=0;i<=n;parent.emplace_back(i++));
        for(auto&e:edges){
            if(get_parent(e[0])==get_parent(e[1])) return e;
            get_union(e[0],e[1]);
        }
        return {};
    }
};