// https://leetcode.com/problems/reveal-cards-in-increasing-order

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& d) {
        sort(d.begin(),d.end());
        int n=d.size();
        queue<int>q;
        for(int i=0;i<n;i++)q.push(i);
        vector<int>ans(n);
        int j=0;
        while(!q.empty()){
            int i=q.front();
            q.pop();
            ans[i]=d[j++];
            i=q.front();
            q.pop();
            q.push(i);
        }
        return ans;
    }
};