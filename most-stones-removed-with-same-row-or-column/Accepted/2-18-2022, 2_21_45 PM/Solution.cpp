// https://leetcode.com/problems/most-stones-removed-with-same-row-or-column

class Solution {
public:
    int sz;
    vector<int> parent;
    int get_parent(int i){
        if(i==parent[i]) return i;
        return parent[i]=get_parent(parent[i]);
    }
    void get_union(int x,int y){
        int rootx = get_parent(x);
        int rooty = get_parent(y);            
        if(rootx == rooty)  return;
        parent[rootx]=rooty;
        sz--;
    }
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        sz=n;
        for(int i=0;i<n;parent.emplace_back(i++));
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++) 
                if(stones[i][0]==stones[j][0] || stones[i][1]==stones[j][1]) get_union(i,j);            
        return n-sz;
    }
};