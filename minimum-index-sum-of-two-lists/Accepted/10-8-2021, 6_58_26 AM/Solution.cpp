// https://leetcode.com/problems/minimum-index-sum-of-two-lists

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string,int>mp;
        for(int i=0;i<list1.size();i++) mp[list1[i]]=i;
        int mn=list1.size()+list2.size();
        vector<string> res;
        for(int i=0;i<list2.size();i++){
            if(mp.count(list2[i])){
                int s=mp[list2[i]]+i;
                if(s<mn){
                    res.clear();
                    res.push_back(list2[i]);
                    mn=s;
                }
                else if(s==mn) res.push_back(list2[i]);
            }
        }
        return res;
    }
};