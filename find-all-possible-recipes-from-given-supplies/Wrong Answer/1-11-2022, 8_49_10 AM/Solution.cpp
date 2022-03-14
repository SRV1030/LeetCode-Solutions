// https://leetcode.com/problems/find-all-possible-recipes-from-given-supplies

class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
       vector<string> ans;
       set<string>st(supplies.begin(),supplies.end());
       for(int i=0;i<recipes.size();i++){
           int f=0;
           for(auto&j:ingredients[i])
               if(!st.count(j)){
                   f=1;
                   break;
               }
           if(!f)st.insert(recipes[i]);
       } 
       for(auto&i:recipes)if(st.count(i))ans.push_back(i); 
       return ans; 
    }
};