// https://leetcode.com/problems/minimum-swaps-to-arrange-a-binary-grid

class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        vector<int>tz;
        int n=grid.size(),ans=0;
        for(auto&i:grid){
            int z=0;
            for(int j=i.size()-1;j>=0;j--){
                if(i[j]) break;
                z++;
            }
            tz.emplace_back(z);
        }
        for(int i=0;i<n;i++){
            int cur=i,req=n-1-i;
            while(cur<n && tz[cur]<req)cur++;
            if(cur==n)return -1;
            ans+=cur-i;
            while(cur>i){
                tz[cur]=tz[cur-1];
                cur--;
            }
        }
        return ans;
    }
};