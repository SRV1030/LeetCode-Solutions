// https://leetcode.com/problems/longest-happy-string

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>,vector<pair<int,char>>>pq;
        if(a>0)pq.push({a,'a'});
        if(b>0)pq.push({b,'b'});
        if(c>0)pq.push({c,'c'});
        string s="";
        char last='z';
        while(!pq.empty()){
           pair<int,char> pr=pq.top();
           pq.pop(); 
           if(pr.second==last){
               if(pq.empty()) break;
               pair<int,char> pr1=pq.top();
               pq.pop();
               s+=pr1.second;
               pr1.first--;
               if(pr1.first>0)pq.push(pr1);
               pq.push(pr);
               last=pr1.second;
           }
           else{                       
               if(pr.first>=2){
                   pr.first-=2;
                   s.push_back(pr.second);
                   s.push_back(pr.second);
               }
                else{
                   pr.first--;
                   s.push_back(pr.second);
                }
                if(pr.first>0)pq.push(pr);
               last=pr.second;
            } 
        }
        return s;
    }
};