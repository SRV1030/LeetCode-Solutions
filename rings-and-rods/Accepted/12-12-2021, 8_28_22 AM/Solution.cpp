// https://leetcode.com/problems/rings-and-rods

class Solution {
public:
    int countPoints(string ring) {
        vector<vector<int>>c(10,vector<int>(3)); 
        int n=ring.size();
        for(int i=0;i<n;i+=2){
            if(ring[i]=='R')c[ring[i+1]-'0'][0]++;
            else if(ring[i]=='B') c[ring[i+1]-'0'][1]++;
            else c[ring[i+1]-'0'][2]++;
        }
        int ans=0;
        for(auto&i:c)
            if(i[0]>=1 && i[1]>=1 && i[2]>=1)ans++;
        
        return ans;
    }
};