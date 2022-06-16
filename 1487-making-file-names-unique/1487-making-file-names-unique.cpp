class Solution {
public:    
    vector<string> getFolderNames(vector<string>& names) {
       unordered_map<string,int>mp;
       vector<string>ans;
        for(auto&n:names){
            string val=n;
            int i=mp[val];
            while(mp[val]>0){
                val=n+"("+to_string(i++)+")";
                mp[n]=i;
            }
            ++mp[val];
            ans.push_back(val);
        }
        return ans;
    }
};