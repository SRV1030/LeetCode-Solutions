// https://leetcode.com/problems/jump-game-iv

class Solution {
public:
    unordered_map<int,vector<int>>mp;
    int minJumps(vector<int>& arr) {
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<arr.size();i++)mp[arr[i]].push_back(i);        
        vector<int>vis(arr.size());
        queue<int>q;
        q.push(0);
        vis[0]++;
        int steps=0;
        while(!q.empty()){
            int n=q.size();
            while(n--){
                int i=q.front();
                if(i==arr.size()-1)return steps;
                q.pop();
                vis[i]++;
                if(i-1>=0)mp[arr[i]].push_back(i-1);
                if(i+1<arr.size())mp[arr[i]].push_back(i+1);
                for(auto&j:mp[arr[i]])
                    if(!vis[j])q.push(j);
                
            }
            steps++;
        }
        return -1;
    }
};