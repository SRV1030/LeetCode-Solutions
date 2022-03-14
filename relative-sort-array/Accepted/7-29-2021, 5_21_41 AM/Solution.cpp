// https://leetcode.com/problems/relative-sort-array

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int,int> mp;
        for(auto& i:arr1)mp[i]++;
        vector<int> v;
        for(auto& i:arr2){
            if(mp.count(i)){
                int n=mp[i];
                while(n--)v.push_back(i);
                mp.erase(i);
            }
        }
        for(auto& i:mp){
            int n=i.second;
            while(n--)v.push_back(i.first);
        }
        return v;
    }
};