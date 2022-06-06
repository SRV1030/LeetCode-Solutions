class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        unordered_map<int,int>mp;        
        for(int i=0;i<size(nums);++i)mp[nums[i]]=i;
        for(auto&i:operations){
            int ind=mp[i[0]];
            nums[ind]=i[1];
            mp.erase(i[0]);
            mp[i[1]]=ind;
        }
        return nums;
    }
};