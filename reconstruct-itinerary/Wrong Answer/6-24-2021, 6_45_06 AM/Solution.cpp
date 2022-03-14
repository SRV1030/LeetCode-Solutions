// https://leetcode.com/problems/reconstruct-itinerary

class Solution {
public:
    int n;
    map<string,vector<string>>mp;
    map<string,int>vis;  
    vector<string>iten;
    void dfs(string cur,vector<string> &places,vector<string> &ans,int trips,bool &f){
        if(trips==n){
            f=true;
            iten=ans;  
            return;
        } 
        for(auto i:places){
            string key=cur+i;
            if(vis[key]>0){
                vis[key]--;
                ans.push_back(i);
                if(!f)dfs(i,mp[i],ans,trips+1,f);
                vis[key]++;
                ans.pop_back();
            }
        }
    }
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {        
        n=tickets.size();
        for(auto i:tickets){
            mp[i[0]].push_back(i[1]);
            string tour=i[0]+i[1];
            vis[tour]++;
        }
        for(auto i:mp) sort(i.second.begin(),i.second.end());
        vector<string>ans;
        ans.push_back("JFK");
        int k=0;
        bool f=false;
        dfs(ans[0],mp[ans[0]],ans,k,f);
         return iten;      
    }
};