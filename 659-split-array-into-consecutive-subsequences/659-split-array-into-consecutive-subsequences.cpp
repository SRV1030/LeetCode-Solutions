class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,int>fm,lm;
        for(auto&i:nums)fm[i]++;
        for(auto&i:nums){
            if(fm[i]==0) continue;
            if(lm[i]>0){
                lm[i]--;
                lm[i+1]++;
                fm[i]--;
            }
            else if(fm[i]>0 && fm[i+1]>0 && fm[i+2]>0){
                lm[i+3]++;
                fm[i]--;fm[i+1]--;fm[i+2]--;
            }
            else return false;
        }
        return true;
    }
};