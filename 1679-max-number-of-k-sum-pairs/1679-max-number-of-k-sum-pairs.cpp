class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int c=0;
        unordered_map<int,int>mp;
        for(auto&i:nums){
            if(mp.count(k-i)){
                c++;
                mp[k-i]--;
                if(!mp[k-i])mp.erase(k-i);
            }
            else mp[i]++;
        }
        return c;
    }
};