class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& p, int k) {
        priority_queue<pair<int,int>>pq;
        pq.push({p[0][1]-p[0][0],p[0][0]});
        int mx=INT_MIN;
        for(int i=1;i<size(p);++i){
            while(!pq.empty() && p[i][0]-pq.top().second>k)pq.pop();
            if(!pq.empty())mx=max(mx,pq.top().first+p[i][0]+p[i][1]);
            pq.push({p[i][1]-p[i][0],p[i][0]});
        }
        return mx;
    }
};