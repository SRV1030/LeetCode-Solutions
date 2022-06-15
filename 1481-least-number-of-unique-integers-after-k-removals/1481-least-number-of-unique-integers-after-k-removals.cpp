class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int>mp;
        for(auto&i:arr)++mp[i];
        priority_queue<int,vector<int>,greater<>>pq;
        for(auto&[ke,v]:mp)pq.push(v);
        while(!pq.empty() && k>0){
            int x=pq.top();
            pq.pop();
            int rem=min(x,k);
            k-=rem;
            if(x>rem)pq.push(x-rem);
        }
        return size(pq);
    }
};