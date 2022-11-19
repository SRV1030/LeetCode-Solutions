class Solution {
public:
    int c=0;
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
        ++c;
    }
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        for(int i=0;i<n;parent.emplace_back(i++));
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++) 
                if(stones[i][0]==stones[j][0] || stones[i][1]==stones[j][1]) get_union(i,j);            
        return c;
    }
};