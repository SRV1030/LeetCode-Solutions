class Solution {
public:
    vector<int> twoSum(vector<int>& n, int t) {
        unordered_map<int,int>mp;
        for(int i=0;i<size(n);++i){
            if(mp.count(t-n[i]))return {mp[t-n[i]]+1,i+1};
            mp[n[i]]=i;
        }
        return {-1,-1};
    }
};