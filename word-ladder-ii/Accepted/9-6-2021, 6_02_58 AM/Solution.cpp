// https://leetcode.com/problems/word-ladder-ii

class Solution {
public: vector<vector<string>> ans;
    void dfs(string beginWord,string endWord,unordered_map<string,set<string>> adj,vector<string> a){
        a.push_back(beginWord);
        if(beginWord==endWord){
            ans.push_back(a);
            return;
        }
        for(auto & x:adj[beginWord]) dfs(x,endWord,adj,a);
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>dict(wordList.begin(),wordList.end());
        if(!dict.count(endWord)) return {};
        unordered_map<string,int>vis;
        unordered_map<string,set<string>>adj;
        queue<string>q;
        q.push(beginWord);
        vis[beginWord]=0;
        while(!q.empty()){
            string cur=q.front(),t=cur;
            q.pop();
            for(int i=0;i<t.size();i++){
                char x=t[i];
                for(char c='a';c<='z';c++){
                    if(t[i]==c) continue;
                    t[i]=c;
                    if(dict.count(t)){
                        if(!vis.count(t)){
                            vis[t]=vis[cur]+1;
                            q.push(t);
                            adj[cur].insert(t);
                        }
                        else if(vis[t]==vis[cur]+1) adj[cur].insert(t);
                    }
                }
                t[i]=x;
            }            
        }
        dfs(beginWord,endWord,adj,{});
        return ans;
    }
};