// https://leetcode.com/problems/reorganize-string

class Solution {
public:
    string reorganizeString(string s) {
        priority_queue<pair<int,char>>pq;
        unordered_map<char,int>mp;
        int n=s.size();
        for(auto& i:s){
            mp[i]++;
            if(mp[i]>(n+1)/2) return "";
        }
        string ans="";
        for(auto& i:mp)pq.push({i.second,i.first});
        while(pq.size()>1){
            char c=pq.top().second;
            pq.pop();
            char d=pq.top().second;
            pq.pop();
            ans=ans+c+d;
            mp[c]--;
            mp[d]--;
            if(mp[c]>0)pq.push({mp[c],c});
            if(mp[d]>0)pq.push({mp[d],d});
        }
        if(pq.size()){
            char c=pq.top().second;
            pq.pop();
            if(mp[c]==1)ans+=c;
            else return "";
        }
        return ans;
    }
    
};