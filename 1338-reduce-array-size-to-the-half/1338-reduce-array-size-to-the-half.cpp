class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int x=arr.size(),n=x/2,c=0;
        unordered_map<int,int>mp;
        for(auto&i:arr)mp[i]++;
        priority_queue<int>pq;
        for(auto& [k,v]:mp)pq.push(v);
        while(!pq.empty()){
            int f=pq.top();
            x-=f;
            c++;
            if(x<=n)return c;
            pq.pop();
        }
        return c;
    }
};