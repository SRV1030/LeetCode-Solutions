// https://leetcode.com/problems/merge-triplets-to-form-target-triplet

class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& trip, vector<int>& t) {
        vector<int>res(3,0);
        for(auto i:trip){
            if(i[0]<=t[0]&& i[1]<=t[1] && i[2]<=t[2]) res={max(res[0],t[0]),max(res[1],t[1]),max(res[2],t[2])};
        }
        return res==t;
    }
};