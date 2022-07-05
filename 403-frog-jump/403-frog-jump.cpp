class Solution {
public:
    unordered_map<long,bool>dp;
    bool canCross(vector<int>& stones,int i=0,int cj=0) {
        long k=i;
        k=k<<32|cj;
        if(dp.count(k))return dp[k];
        for(int j=i+1;j<size(stones);++j){
            int gap=stones[j]-stones[i];
            if(gap<cj-1)continue;
            else if(gap>cj+1)return dp[k]=false;
            else if(canCross(stones,j,gap))return dp[k]=true;
        }
        return dp[k]=(i==size(stones)-1);
        
    }
};