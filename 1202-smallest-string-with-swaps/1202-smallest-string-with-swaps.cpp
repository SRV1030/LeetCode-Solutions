class Solution {
public:
    vector<int>p;
    int getP(int i){
        return i==p[i]?p[i]:p[i]=getP(p[i]);
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n=s.size();
        vector<vector<int>>v(n);
        for(int i=0;i<=n;p.push_back(i++));
        for(auto&i:pairs){
            int p1=getP(i[0]),p2=getP(i[1]);
            if(p1!=p2)p[p2]=p1;
        }
        for(int i=0;i<n;i++)v[getP(i)].push_back(i);
        for(auto&i:v){
            string ss="";
            for(auto&j:i)ss+=s[j];
            sort(ss.begin(),ss.end());
            for(int id=0;id<i.size();id++)s[i[id]]=ss[id];
        }
        return s;
    }
};