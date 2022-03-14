// https://leetcode.com/problems/keys-and-rooms

class Solution {
public:
    vector<bool>vis;
    void dfs(int i,vector<vector<int>>& rooms){
        vis[i]=true;
        for(auto&x:rooms[i])
            if(!vis[x])dfs(x,rooms);
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vis=vector<bool>(rooms.size(),false);
        dfs(0,rooms);
        for(int i=0;i<rooms.size();i++)if(!vis[i]) return false;
        return true;
    }
};