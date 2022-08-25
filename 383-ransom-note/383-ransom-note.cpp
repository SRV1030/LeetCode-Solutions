class Solution {
public:
    bool canConstruct(string r, string m) {
        vector<int>f(26);
        for(auto& i:m)f[i-'a']++;
        for(auto& i:r){
            f[i-'a']--;
            if(f[i-'a']<0) return false;
        }
        return true;
    }
};