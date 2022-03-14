// https://leetcode.com/problems/sort-the-jumbled-numbers

class Solution {
public:
    int getVal(vector<int>& mapping,int num){
        string v=to_string(num);
        for(auto&i:v)i=mapping[i-'0']+'0';
        return stoi(v);
    }
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto&i:nums)mp[i]=getVal(mapping,i);
        sort(nums.begin(),nums.end(),[&mp](int a,int b){return mp[a]<mp[b];});
        return nums;
    }
};