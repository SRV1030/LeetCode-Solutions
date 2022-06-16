class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int,int>mp;
        for(auto&i:arr){
            i=((i%k)+k)%k;
            ++mp[i];
        }
        for(auto&i:arr)
            if((!i && mp[i]%2) || (i && mp[i]!=mp[k-i])) return false;        
        return true;
    }
};