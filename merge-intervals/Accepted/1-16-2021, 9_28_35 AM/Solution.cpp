// https://leetcode.com/problems/merge-intervals

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& v) {
        vector<vector<int>> m;
        if(v.size()==0) return m;
        sort(v.begin(),v.end());
        vector<int>temp=v[0];
        for(auto it:v){
            if(it[0]<=temp[1]){
                temp[1]=max(it[1],temp[1]);
            }
            else{
                m.push_back(temp);
                temp=it;
            }
        }
        m.push_back(temp);
        return m;
        
    }
};