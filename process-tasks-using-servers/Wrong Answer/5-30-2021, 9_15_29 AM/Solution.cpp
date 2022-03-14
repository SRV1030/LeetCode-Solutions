// https://leetcode.com/problems/process-tasks-using-servers

class Solution {
public:
    vector<int> assignTasks(vector<int>& s, vector<int>& t) {
         vector<int> v(t.size(),-1);
         vector<pair<int,int>>srv;
               
         for(int i=0;i<s.size();i++)srv.push_back({s[i],i});
         sort(srv.begin(),srv.end());
        int f=0;
         for(auto i:srv){
             for(int j=0;j<t.size();){
                 if(v[j]==-1){
                     v[j]=i.second;
                     j+=t[j];
                     f++;
                 }
                 else j++; 
             }
             if(f==t.size()) break;
         }
        return v;
        
    }
};