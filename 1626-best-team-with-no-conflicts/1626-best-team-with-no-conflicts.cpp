class Solution {
public:
    int bestTeamScore(vector<int>& sc, vector<int>& ag) {
        vector<vector<int>>v;
        for(int i=0;i<sc.size();i++)v.push_back({ag[i],sc[i]});
        sort(v.begin(),v.end(),greater<>());
        int dp[sc.size()+1],mx=1;
        dp[0]=v[0][1];
        for(int i=1;i<sc.size();i++){
            dp[i]=v[i][1];
            for(int j=0;j<i;j++){
                if(v[j][1]>=v[i][1])dp[i]=max(dp[i],v[i][1]+dp[j]);
            }
            mx=max(mx,dp[i]);
        }
        return mx;    
    }
};