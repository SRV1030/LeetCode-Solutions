// https://leetcode.com/problems/sort-integers-by-the-power-value

class Solution {
public:
    vector<int>dp;
    int val(int x){
        if(x==1) return 0;
        if(x<=1000 && dp[x]!=-1 ) return dp[x];
        if(x%2) return x<=1000?dp[x]=val(3*x+1)+1:val(3*x+1)+1;
        else return x<=1000?dp[x]=val(x/2)+1:val(x/2)+1;
    }
    int getKth(int lo, int hi, int k) {
        dp=vector<int>(1001,-1);
        priority_queue<pair<int,int>>pq;
        for(int i=lo;i<=hi;i++){
            pq.push({val(i),i});
            if(pq.size()>k) pq.pop();            
        }
        return pq.top().second;
    }
};