class Solution {
public:
    class node{
        public:
        string dest;
        double wt;
        node(string d,double w){
            dest=d;
            wt=w;
        }
    };    
    unordered_map<string,vector<node>>mp;
    double dfs(string src,string des,unordered_set<string>vis){
        if(!mp.count(src) || !mp.count(des)) return -1;
        if(src==des) return 1;
        vis.insert(src);
        for(auto&i:mp[src])
           if(!vis.count(i.dest)){
             double ans=dfs(i.dest,des,vis);
             if(ans!=-1) return ans*i.wt;
           } 
        
        return -1;
    }
    vector<double> calcEquation(vector<vector<string>>& eq, vector<double>& v, vector<vector<string>>& q) {
        int nv=v.size(),nq=q.size();
        for(int i=0;i<nv;i++){
            mp[eq[i][0]].push_back({eq[i][1],v[i]});
            mp[eq[i][1]].push_back({eq[i][0],1/v[i]});
        }       
        vector<double> ans(nq);
        unordered_set<string>vis;
        for(int i=0;i<nq;i++)
            ans[i]=dfs(q[i][0],q[i][1],vis);
        return ans;
    }
};