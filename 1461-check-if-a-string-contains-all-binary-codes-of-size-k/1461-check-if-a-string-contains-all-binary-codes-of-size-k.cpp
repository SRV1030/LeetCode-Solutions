class Solution {
public:
    bool hasAllCodes(string s, int k) {
        long nk=1<<k,ns=s.size();
        unordered_set<string>st;
        for(int i=0;i<=ns-k;++i){
            string sb=s.substr(i,k);
            if(!st.count(sb))st.insert(sb);
        }
        return st.size()==nk;
    }
};