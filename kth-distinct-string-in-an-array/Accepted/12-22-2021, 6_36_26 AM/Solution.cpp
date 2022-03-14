// https://leetcode.com/problems/kth-distinct-string-in-an-array

class Solution {
public:
    string kthDistinct(vector<string>& arr, int n) {
        unordered_map<string,int>mp;
        for(auto& i:arr)mp[i]++;
        for(auto& i:arr){
            if(mp[i]==1)n--;
            if(n==0)return i;
        }
        return "";
    }
};