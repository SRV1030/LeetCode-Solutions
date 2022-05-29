class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        mp[0]=-1;
        int s=0,c=0,rt=-1;
        for(int i=0;i<size(nums);++i){
            s+=nums[i];
            if(mp.count(s-target)){
                int lt=mp[s-target];
                if(rt<=lt){
                    c++;
                    rt=i;
                }
            }
            mp[s]=i;
        }
        return c;
    }
};