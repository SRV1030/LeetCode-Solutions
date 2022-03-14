// https://leetcode.com/problems/replace-the-substring-for-balanced-string

class Solution {
public:
    unordered_map<char,int>mp;
    int lt,n;
    bool isbal(){
        return mp['Q']<=lt && mp['W']<=lt && mp['E']<=lt && mp['R']<=lt;
    }
    int balancedString(string s) {
        n=s.size(),lt=n/4;
        mp['Q']=0;mp['W']=0;mp['E']=0;mp['R']=0;
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
            }
            j++;
            if(isbal())mn=min(mn,j-i+1);
        }
        return mn;
    }
};