class Solution {
public:
    vector<int> minOperations(string b) {
        int n=b.size();
        vector<int>ans(n),v;
        for(int i=0;i<n;i++)if(b[i]=='1')v.emplace_back(i);
        for(int i=0;i<n;i++)
            for(auto&j:v)ans[i]+=abs(j-i);
        return ans;        
    }
};