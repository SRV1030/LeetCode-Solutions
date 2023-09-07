class Solution {
public:
    long long maxSum(vector<int>& num, int m, int k) {
        long long un=0,sm=0,ans=0;
        unordered_map<int,int>mp;
        for(int l=0,r=0;r<size(num);++r){
            sm+=num[r];
            ++mp[num[r]];
            if(mp[num[r]]==1) ++un;
            if(r>=k){
                sm-=num[l];
                --mp[num[l]];
                if(mp[num[l]]==0)--un;
                ++l;      
            }
            if(un>=m)ans=max(ans,sm);          
        }
        return ans;
    }
};