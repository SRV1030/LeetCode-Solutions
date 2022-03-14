// https://leetcode.com/problems/find-all-possible-recipes-from-given-supplies

class Solution {
public:
    
   unordered_map<string,vector<string>>mp;
   unordered_map<string,int>vis;
   bool dfs(string i){
       if(vis[i]==3)return true;
       if(vis[i]==2 || !mp.count(i)) return false;
       bool exs=true;
       vis[i]=1;
       for(auto&j:mp[i]){
           if(vis[j]==1 || vis[j]==2){
               vis[i]=vis[j]=2;
               return false;
           }
           else exs&=dfs(j);
       }
       if(exs) vis[i]=3;
       else vis[i]=2;
       return exs;
   } 
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        vector<string> ans;
        for(auto&i:supplies)vis[i]=3;
        for(int i=0;i<recipes.size();i++) mp[recipes[i]]=ingredients[i];
        for(auto&i:recipes)if(dfs(i)) ans.push_back(i);
        return ans;       
    }
};