class Solution {
public:
    int minDeletions(string s) {
        unordered_set<int>st;
        vector<int>v(26);
        for(auto&i:s)v[i-'a']++;
        int res=0;
        for(int i=0;i<26;i++)
            for(;v[i]>0 && !st.insert(v[i]).second;v[i]--)res++;
        return res;
    }
};