// https://leetcode.com/problems/find-center-of-star-graph

// class Solution {
// public:
//     int findCenter(vector<vector<int>>& edges) {
//         unordered_map<int,int>mp;
//         for(auto&i:edges){
//             mp[i[0]]++;
//             mp[i[1]]++;
//         }
//         int n=mp.size();
//         for(auto&[k,v]:mp)
//             if(v==n-1) return k;
//         return -1;
//     }
// };
class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int cf=edges[0][0],ct=edges[0][1], nf=edges[1][0],nt=edges[1][1];
        if(cf==nf || ct==nt) return cf;
        else return ct;
    }
};