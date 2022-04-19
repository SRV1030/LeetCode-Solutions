class Solution {
public:
    string digitSum(string s, int k) {
        if(s.size()<=k) return s;
        string ans;
        for(int i=0;i<s.size();i+=k){
            string n=s.substr(i,min(k,(int)s.size()-i));
            int v=0;
            for(auto&i:n)v+=(i-'0');
            ans+=to_string(v);
        }
        return digitSum(ans,k);
    }
};