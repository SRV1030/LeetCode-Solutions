// https://leetcode.com/problems/print-words-vertically

class Solution {
public:
    vector<string> printVertically(string s) {
        s+=" \n";
        stringstream str(s);
        string t="";
        vector<string> v;
        int mx=0;
        while(1) {
            getline(str,t,' ');
            if(t!="\n"){
                v.push_back(t);
                if(t.size()>mx)mx=t.size();
            }
            else break;
        }
        
        int n=v.size();
        vector<int> mv(n);
        mv[n-1]=v[n-1].size();
        for(int i=n-2;i>=0;i--)mv[i]=v[i].size()>mv[i+1]?v[i].size():mv[i+1];
        vector<string>ans(mx);
        for(int i=0;i<n;i++){
            int sz=v[i].size();
            for(int j=0;j<mv[i];j++){
                if(j<sz)ans[j].push_back(v[i][j]);
                else ans[j].push_back(' ');
            }
        }
        return ans;
    }
};