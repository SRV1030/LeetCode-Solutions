// https://leetcode.com/problems/longest-happy-string

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>,vector<pair<int,char>>>pq;
        pq.push({a,'a'});
        pq.push({b,'b'});
        pq.push({c,'c'});
        vector<int>v(3,0);
        string s="";
        bool f=true;
        while(!pq.empty()){
           pair<int,char> pr=pq.top();
           pq.pop();           
           if(pr.first>=2){
               pr.first-=2;
               s.push_back(pr.second);
               s.push_back(pr.second);
           }
            else{
                pr.first--;
               s.push_back(pr.second);
            }
        if(!pq.empty()){
             pair<int,char> pr1=pq.top();
           pq.pop();          
           if(pr1.first>=2){
               pr1.first-=2;
               s.push_back(pr1.second);
               s.push_back(pr1.second);
           }
            else{
               pr1.first--;
               s.push_back(pr1.second);
            }
            if(pr1.first>0)pq.push(pr1);
        } else break;
           if(pr.first>0)pq.push(pr);
            
        }
        return s;
    }
};