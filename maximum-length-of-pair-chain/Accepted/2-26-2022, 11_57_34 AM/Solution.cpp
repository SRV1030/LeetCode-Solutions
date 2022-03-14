// https://leetcode.com/problems/maximum-length-of-pair-chain

// class Solution {
// public:
//     int findLongestChain(vector<vector<int>>& pairs) {
//         sort(pairs.begin(),pairs.end());
//         vector<int>dp;
//         for(auto&p:pairs){
//             auto itr=lower_bound(dp.begin(),dp.end(),p[0]);
//             if(itr==dp.end())dp.push_back(p[1]);
//             else if(*itr>p[1])*itr=p[1];
//         }
//         return dp.size();
//     }
// };

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        vector<pair<int,int>>v;
        for(int i=0;i<pairs.size();i++)v.push_back({pairs[i][0],pairs[i][1]});
        sort(v.begin(),v.end(),[](pair<int,int> a,pair<int,int> b){return a.second<b.second;});
        pair<int,int> x=v[0];
        int c=1;
        for(int i=1;i<v.size();i++){
            if(v[i].first>x.second){
                c++;
                x=v[i];
            }
        }
        return c;
            
        
    }
};