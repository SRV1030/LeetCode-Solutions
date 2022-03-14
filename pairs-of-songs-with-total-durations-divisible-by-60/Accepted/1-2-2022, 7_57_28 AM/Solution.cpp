// https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int c=0;
        vector<int>v(60,0);
        for(int i=0;i<time.size();i++){
            int p=time[i]%60;
            if(p==0)c+=v[0];
            else c+=v[60-p];
            v[p]++;
        }
        return c;       
        
    }
};