// https://leetcode.com/problems/the-skyline-problem

class Solution {
public:
    static bool comp(pair<pair<int,int>,int>&a, pair<pair<int,int>,int>&b){
        //first sort by x-coordinate
        if(a.first.first != b.first.first)
            return a.first.first < b.first.first;
        //if both starting at same point, greater height is picked first
        if(a.second==0 && b.second==0)
            return a.first.second > b.first.second;
        //if both ending at same point, lower height is picked first
        if(a.second==1 && b.second==1)
            return a.first.second < b.first.second;
        //if one starting and one ending, start should come first (i.e. 0 < 1)
        return a.second < b.second;
    }
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        int n = buildings.size();
        vector<pair<pair<int,int>,int>>v;
        for(int i=0; i<n; i++){
            v.push_back({{buildings[i][0],buildings[i][2]},0}); //0 means start
            v.push_back({{buildings[i][1],buildings[i][2]},1}); //1 means end
        }
        
        sort(v.begin(),v.end(),comp);
        
        vector<vector<int>>ans;
        multiset<int, greater<int>>ms;
        ms.insert(0);
        int maxH = 0;
        
        for(auto p: v){
            int x = p.first.first;
            int height = p.first.second;
            int type = p.second;
            
            //start
            if(type == 0){
                ms.insert(height);
                
            }
            //end
            else{
                //ms.erase(height);
                auto it = ms.find(height); 
                if(it != ms.end()) ms.erase(it);
            }
            int mx = *ms.begin();
            if(mx != maxH){
                maxH = mx;
                ans.push_back({x,maxH});
            }
        }
        return ans;
    }
};