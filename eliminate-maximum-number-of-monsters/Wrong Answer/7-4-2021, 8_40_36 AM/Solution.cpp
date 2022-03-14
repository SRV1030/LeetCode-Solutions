// https://leetcode.com/problems/eliminate-maximum-number-of-monsters

class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int ans=1;
        for(int i=1;i<dist.size();i++){
            int d=dist[i]-speed[i]*i;
            if(d<=0) return ans;
            ans++;            
        }
        return ans;
    }
};