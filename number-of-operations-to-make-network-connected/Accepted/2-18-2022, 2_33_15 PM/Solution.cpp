// https://leetcode.com/problems/number-of-operations-to-make-network-connected

class Solution {
public:
    
    vector<int> parent;
    vector<int> rank;
    
    int findPar(int u){
        if(parent[u]==u) return u;
        return parent[u]=findPar(parent[u]); //path compresssion, storing the computed value;
    }
    
    void unionn(int u, int v){
        u= findPar(u);
        v= findPar(v);
        if(rank[u]<rank[v])
            parent[u]=v;
        else if(rank[v]<rank[u])
            parent[v]=u;
        else {
            parent[v]=u;
            rank[u]++;
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& conn) {
        if(conn.size()< n-1) return -1; // to combine n computer we require n-1 wires but here it's not the case
        
        //filling parent and rank array;
        for(int i=0;i<n;i++)
            parent.push_back(i), rank.push_back(0);
        
        //iterating to connection array and connecting them
        for(auto &it: conn)
            unionn(it[0], it[1]);
        
        //counting number of different components;
        int differentComponents= 0;
        for(int i=0;i<n;i++)
            if(parent[i]==i) differentComponents++;
        
        //total {DifferentComponents} components are there and we need to join them in mininimum cable 
        //so best way to join them will be linearly( think ) which will require DifferentComponents-1 cables only;
        return differentComponents-1;
    }
};