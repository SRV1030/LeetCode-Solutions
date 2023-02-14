class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        long long c=0;
        priority_queue<int>pq(begin(gifts),end(gifts));
        while(!pq.empty() && k--){
            int x=sqrt(pq.top());
            pq.pop();
            pq.push(x);
        }
        while(!pq.empty()){
            c+=pq.top();
            pq.pop();
        }
        return c;
    }
};