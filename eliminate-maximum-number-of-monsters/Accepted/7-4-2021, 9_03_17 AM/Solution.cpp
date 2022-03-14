// https://leetcode.com/problems/eliminate-maximum-number-of-monsters

class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int ans=0;
        vector<pair<int,int>>v;
        for(int i=0;i<dist.size();i++)v.push_back({dist[i],speed[i]});
        sort(v.begin(),v.end(),
               [](pair<int,int> a,pair<int,int> b){
                    double x=(double)a.second/a.first,y=(double)b.second/b.first;
                   // cout<<x<<y<<" ";
                    return x>y;});
        
        for(int i=0;i<dist.size();i++){
            // cout<<v[i].first<<"+"<<v[i].second<<" ";
            int d=v[i].first-v[i].second*i;
            if(d<=0) return ans;
            ans++;            
        }
        return v.size();
    }
};