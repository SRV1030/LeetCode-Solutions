// https://leetcode.com/problems/degree-of-an-array

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int,int>mp;
        int mf=0,n=nums.size();
        for(auto& i:nums){
            mp[i]++;
            if(mp[i]>mf) mf=mp[i];
        }
        if(mf==1)return 1;
        int mn=INT_MAX;
        for(auto& i:mp){
            if(i.second==mf){
                int l=0,r=n-1;
                while(l<=r && nums[l]!=i.first)l++;
                while(l<=r && nums[r]!=i.first)r--;
                mn=min(mn,r-l+1);                   
            }
        }        
        return mn;
    }
};