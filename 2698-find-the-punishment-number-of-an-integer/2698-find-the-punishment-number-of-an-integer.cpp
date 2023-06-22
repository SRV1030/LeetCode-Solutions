class Solution {
public:
    bool check(string &x,int ind,int t){
        if(t<0) return false;
        if(ind==size(x)) return t==0;
        for(int i=ind;i<size(x);++i){
            string nx=x.substr(ind,i-ind+1);
            int v=stoi(nx);
            if(check(x,i+1,t-v))return true;
        }
        return false;
    }
    int punishmentNumber(int n) {
        int ans=0;
        for(int i=1;i<=n;++i){
            int x=i*i;
            string s=to_string(x);
            if(check(s,0,i)) ans+=x;
        }
        return ans;
    }
};