// https://leetcode.com/problems/palindrome-partitioning

class Solution {
public:
    vector<vector<string>>v;
    vector<string> p;
    bool ispal(string s,int i,int j){
        while(i<=j)
            if(s[i++]!=s[j--]) return false;
        return true;
    }
    void util(string s,int ind){
        if(ind==s.size()){
            v.push_back(p);
            return;
        }
        for(int i=ind;i<=s.size();i++){
            if(ispal(s,ind,i)){
                p.push_back(s.substr(ind,i-ind+1));
                util(s,i+1);
                p.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        util(s,0);
        return v;
    }
};