// class Solution {
// public:
//     vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
//         map<int,int>mp;
//         for(auto&i:nums)++mp[i];
//         for(int i=0;i<size(moveFrom);++i)
//             if(moveTo[i]!=moveFrom[i] && mp.count(moveFrom[i])){
//                 mp[moveTo[i]]+=mp[moveFrom[i]];
//                 mp.erase(moveFrom[i]);
//             }   
//         vector<int>ans;
//         for(auto&[k,v]:mp)ans.push_back(k);
//         return ans;
//     }
// };

class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
        set<int> s(begin(nums), end(nums));
        for (int i = 0; i < moveFrom.size(); ++i) {
            s.erase(s.find(moveFrom[i]));
            s.insert(moveTo[i]);
        }
        return vector<int>(begin(s), end(s));
    }
};

