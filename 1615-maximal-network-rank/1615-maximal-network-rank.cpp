class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<unordered_set<int>>v(n);
        for(auto&i:roads){
            v[i[0]].insert(i[1]);
            v[i[1]].insert(i[0]);            
        }
        int mx=0;
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++){
                int c=v[i].size()+v[j].size()-((v[i].count(j))?1:0);
                mx=max(c,mx);
            }
        return mx;
    }
};