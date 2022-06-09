class Solution {
public:
    int reg[21]={0};
    int maximumRequests(int n, vector<vector<int>>& r,int i=0) {
        if(i==size(r)){
            int c=0;
            for(int i=0;i<n;++i)c+=reg[i]==0;
            return c==n?0:INT_MIN;
        }
        ++reg[r[i][0]];
        --reg[r[i][1]];
        int take=1+maximumRequests(n,r,i+1);
        --reg[r[i][0]];
        ++reg[r[i][1]];
        return max(take,maximumRequests(n,r,i+1));
    }
};