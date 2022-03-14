// https://leetcode.com/problems/maximum-profit-in-job-scheduling

class Solution {
public:
    int jobScheduling(vector<int>& st, vector<int>& et, vector<int>& pr) {
        int n=st.size();
        vector<vector<int>>v(n);
        for(int i=0;i<n;i++)v[i]={et[i],st[i],pr[i]};
        sort(v.begin(),v.end());
        map<int,int>mp={{0,0}};
        int mx=0;
        for(auto &i:v){
            int cur = prev(mp.upper_bound(i[1]))->second + i[2]; 
            if (cur > mp.rbegin()->second)
                mp[i[0]] = cur;
        }
        return mp.rbegin()->second;
    }
};