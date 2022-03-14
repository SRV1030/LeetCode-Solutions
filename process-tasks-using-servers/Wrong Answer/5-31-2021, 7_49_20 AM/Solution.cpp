// https://leetcode.com/problems/process-tasks-using-servers

class Solution {
public:
    vector<int> assignTasks(vector<int>& s, vector<int>& t) {
         priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>ps;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>>pw;
        for(int i=0;i<s.size();i++)ps.push({s[i],i});
        int time=0;
        vector<int> res;
        for(int i=0;i<t.size();i++){
            if(!pw.empty()){
                if(pw.top().first<=i){
                    pair<int,int> temp=pw.top().second;
                    pw.pop();
                    ps.push(temp);
                }
            }
            if(!ps.empty()){
                res.push_back(ps.top().second);
                pw.push({i+t[i],ps.top()});
                ps.pop();                
            }
            else{
                pair<int,pair<int,int>> temp=pw.top();
                res.push_back(temp.second.second);
                pw.pop();
                pw.push({i+t[i],temp.second});
            }
            
            
        }
        
        return res;
    }
        
};