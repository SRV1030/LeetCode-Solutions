// https://leetcode.com/problems/replace-the-substring-for-balanced-string

class Solution {
public:
    unordered_map<char,int>mp;
    int lt,n;
    bool isbal(){
        for(auto&i:mp)
            if(i.second>lt) return false;
        return true;
    }
    int balancedString(string s) {
        n=s.size(),lt=n/4;
        for(auto& i:s)mp[i]++;
        if(isbal()) return 0;
        int i=0,j=0,mn=INT_MAX;
        while(j<n){
            while(j<n && !isbal()){
                mp[s[j]]--;
                j++;
            }
            j--;
            mn=min(mn,j-i+1);
            while(i<=j && isbal()){
                mp[s[i]]++;
                i++;
                if(isbal())mn=min(mn,j-i+1);
            }
            j++;
        }
        return mn;
    }
};