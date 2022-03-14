// https://leetcode.com/problems/eliminate-maximum-number-of-monsters

class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int ans=1;
        for(int i=1;i<dist.size();i++){
            int c=speed[i]/dist[i];
            if(c>=1) return ans;
            ans++;            
        }
        return ans;
    }
};