// https://leetcode.com/problems/most-beautiful-item-for-each-query

class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(),items.end());
        map<int,int>mp;
        int mx=0;
        for(auto& i:items){
            if(i[1]>mx){
                mx=i[1];
                mp[i[0]]=mx;
            }
        }
        vector<int>ans;
        for(auto& i:queries){
            auto it= mp.upper_bound(i);
            if(it==mp.begin())ans.push_back(0);
            else {
                advance(it, -1);
                ans.push_back(it->second);
            }
        }
        return ans;
    }
};