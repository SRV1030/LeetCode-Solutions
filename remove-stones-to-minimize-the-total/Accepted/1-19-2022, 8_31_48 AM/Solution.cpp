// https://leetcode.com/problems/remove-stones-to-minimize-the-total

class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int>pq(piles.begin(),piles.end());
        while(k--){
            int x=pq.top();
            pq.pop();
            pq.push(x-x/2);
        }
        int s=0;
        while(!pq.empty()){
            s+=pq.top();
            pq.pop();
        }
        return s;
    }
};