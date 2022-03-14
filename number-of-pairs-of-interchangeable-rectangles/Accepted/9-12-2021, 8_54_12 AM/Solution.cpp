// https://leetcode.com/problems/number-of-pairs-of-interchangeable-rectangles

class Solution {
public:
    long long npr(int n){
        long long dp[n+1],s=0;
        dp[0]=0;
        for(long long i=1;i<n;i++){
            dp[i]=1+dp[i-1];            
            s+=dp[i];
        }
        return s;
    }
    long long interchangeableRectangles(vector<vector<int>>& r) {
        unordered_map<double,long long>mp;
        long long ans=0;
        for(auto& i:r) mp[((double)i[0]/(double)i[1])]++;
        for(auto& i:mp)
            if(i.second>1)ans+=npr(i.second);
        return ans;
    }
};