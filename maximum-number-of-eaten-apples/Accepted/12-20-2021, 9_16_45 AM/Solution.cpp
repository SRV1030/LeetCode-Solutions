// https://leetcode.com/problems/maximum-number-of-eaten-apples

class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
        int ans=0, n=apples.size();
        for(int i=0;i<n;i++){
            if(days[i]>0 && apples[i]>0) pq.push({days[i]+i-1, apples[i]});
            while(!pq.empty() && pq.top().first<i) pq.pop();
            if(pq.empty()) continue;
            ans++;
            pair<int,int> p = pq.top();
            pq.pop();
            p.second -= 1;
            if(p.second) pq.push(p);
        }
        int cd=n;
        while(!pq.empty()){
            while(!pq.empty() && pq.top().first < cd) pq.pop();
            if(pq.empty()) return ans;
            int nd = min(pq.top().first-cd+1, pq.top().second);
            ans+=nd;
            cd+=nd;
            pq.pop();
            
        }
        return ans;
    }
};