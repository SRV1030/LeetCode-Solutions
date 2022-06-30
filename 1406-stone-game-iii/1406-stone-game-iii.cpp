class Solution {
public:
    vector<int>dp;
    int aminusb(vector<int>& sv,int i){
        if(i>=sv.size()) return 0;
        if(dp[i]!=-1)return dp[i];        
        int ans=max(INT_MIN,sv[i]-aminusb(sv,i+1));
        if(i+1<sv.size())ans=max(ans,sv[i]+sv[i+1]-aminusb(sv,i+2));
        if(i+2<sv.size())ans=max(ans,sv[i]+sv[i+1]+sv[i+2]-aminusb(sv,i+3));
        return dp[i]=ans;        
    }
    string stoneGameIII(vector<int>& sv) {
        dp.assign(sv.size()+1,-1);
        int res=aminusb(sv,0);
        return res==0?"Tie":res<0?"Bob":"Alice";
    }
};