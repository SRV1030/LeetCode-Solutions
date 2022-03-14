// https://leetcode.com/problems/find-all-anagrams-in-a-string

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(p.size()>s.size()) return{};
        vector<int> v;
        int n=s.size(),m=p.size();
        sort(p.begin(),p.end());
        for(int i=0;i<n-m+1;i++){
            string t=s.substr(i,m);
            // cout<<t<<" ";
            sort(t.begin(),t.end());
            if(t==p)v.push_back(i);
        }
        return v;
    }
};