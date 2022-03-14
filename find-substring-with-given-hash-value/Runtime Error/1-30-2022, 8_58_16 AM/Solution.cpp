// https://leetcode.com/problems/find-substring-with-given-hash-value

class Solution {
public:
    int md;
    int po(int a,int b){
        if(b==0) return 1;
        if(a==0) return 0;
        int x=1;
        while(b>0){
            if(b&1)x=(x*a)%md;
            b>>=1;
            a=(a*a)%md;
        }
        return x%md;
    }
    int hash(string s,int p){
        int v=0;
        for(int i=0;i<s.size();i++){
            v=(v%md+(((s[i]-'a'+1)%md)*po(p,i))%md)%md;
        }
        return v;
    }
    string subStrHash(string s, int power, int modulo, int k, int hashValue) {
        md=modulo;
        while(s.size()>=k){
            string t=s.substr(0,k);
            int h=hash(t,power);
            if(h==hashValue) return t;
            s.erase(s.begin());
        }
        return "";
    }
};