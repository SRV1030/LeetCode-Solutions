// https://leetcode.com/problems/degree-of-an-array

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int,int>mp;
        int mf=0,me=0;
        for(auto& i:nums){
            mp[i]++;
            if(mp[i]>mf){
                mf=mp[i];
                me=i;
            }
        }
        int mn=INT_MAX,l=0,c=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==me)c++;
            if(c==mf){
                while(l<=i && c==mf){
                    if(mn>i-l+1)mn=i-l+1;
                    if(nums[l]==me)c--;
                    l++;
                }
            }      
        }
        return mn;
    }
};