// https://leetcode.com/problems/car-pooling

class Solution {
public:
    bool carPooling(vector<vector<int>>& v, int capacity) {
        sort(v.begin(),v.end(),
             [](vector<int>a,vector<int>b){return a[1]<b[1];});        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;    
        int psg=0;
        for(auto&i:v){
            int nxtSt=i[1];
            while(!pq.empty() && nxtSt>=pq.top().first){
                psg-=pq.top().second;
                pq.pop();
            }
            psg+=i[0];
            if(psg>capacity) return false;
            pq.push({i[2],i[0]});
        }
        return true;
        
    }
};