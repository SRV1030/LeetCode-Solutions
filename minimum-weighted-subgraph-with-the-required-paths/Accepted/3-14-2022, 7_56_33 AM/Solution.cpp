// https://leetcode.com/problems/minimum-weighted-subgraph-with-the-required-paths

#define pp pair<long long,long long>
class Solution {
public:
    void shortestPath(vector<vector<pp>>g,vector<long long>&dist,int start){
        priority_queue<pp,vector<pp>,greater<pp>>pq;
        pq.push({0,start});
        while(!pq.empty()){
            auto [wt,u]=pq.top();
            pq.pop();
            if(dist[u]!=wt)continue;
            for(auto [uu,wt2]:g[u]){
                // cout<<u<<" "<<uu<<" ";
                if(dist[uu]>dist[u]+wt2){
                    dist[uu]=dist[u]+wt2;
                    pq.push({dist[uu],uu});
                }
            }
        }
    }
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
         vector<vector<pp>>g(n),g1(n);
        //let n1 be the point where src1 and src2 meets
        for(auto edge:edges){
            g[edge[0]].push_back({edge[1],edge[2]});
            //g1 an opposite graph to get the dest to n1(where src1 and src2 meets)
            g1[edge[1]].push_back({edge[0],edge[2]});
        }
        
        vector<long long>dista(n,LONG_MAX),distb(n,LONG_MAX),distn(n,LONG_MAX);
        dista[src1]=distb[src2]=distn[dest]=0;
        shortestPath(g,dista,src1);
        shortestPath(g,distb,src2);
        shortestPath(g1,distn,dest);
        long long ans=LONG_MAX;
        for(int i=0;i<n;i++){
            if(dista[i]==LONG_MAX||distb[i]==LONG_MAX||distn[i]==LONG_MAX)continue;
            ans=min(ans,dista[i]+distb[i]+distn[i]);
        }
        return ans==LONG_MAX?-1:ans;
    }
};