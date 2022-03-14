// https://leetcode.com/problems/jump-game-iv

class Solution {
public:
    unordered_map<int,vector<int>>mp;
    int dfs(vector<int>& arr,vector<int>& vis,int i){
        if(i==vis.size()-1) return 0;
        vis[i]++;
        int c=INT_MAX;
        for(auto& j:mp[arr[i]]){
            if(!vis[j]){
                int z=dfs(arr,vis,j);
                if(z!=-1 && z+1<c)c=z+1;
            }
            
        }
        return c==INT_MAX?-1:c;
    }
    int minJumps(vector<int>& arr) {
        for(int i=0;i<arr.size();i++){
            if(!mp.count(arr[i]))mp[arr[i]]={i};
            else{
                mp[arr[i]].push_back(i);
                if(i-1>=0)mp[arr[i]].push_back(i-1);
                if(i+1<arr.size())mp[arr[i]].push_back(i+1);
            }
        }
        vector<int>vis(arr.size());
        return dfs(arr,vis,0);
    }
};