// https://leetcode.com/problems/two-best-non-overlapping-events

class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& e) {
        int ne= e.size(),ans=0,mx=0;
        sort(e.begin(),e.end());
        map<int,int>mp;
        while(ne--){
            auto it=mp.upper_bound(e[ne][1]);
            mx=max(mx,e[ne][2]);
            mp[e[ne][0]]=mx;
            if(it==mp.end())ans=max(ans,mx);
            else ans=max(ans,e[ne][2]+it->second);            
        }
        return ans;
    }
};