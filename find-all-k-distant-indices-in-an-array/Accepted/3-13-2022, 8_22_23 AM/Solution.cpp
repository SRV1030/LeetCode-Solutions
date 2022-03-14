// https://leetcode.com/problems/find-all-k-distant-indices-in-an-array

class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int>keys;
        for(int i=0;i<nums.size();i++)if(nums[i]==key)keys.push_back(i);
        set<int>ans;
        for(auto&i:keys){
            for(int j=0;j<nums.size();j++){
                if(abs(j-i)<=k)ans.insert(j);
            }
        }
        return vector<int>(ans.begin(),ans.end());            
    }
};