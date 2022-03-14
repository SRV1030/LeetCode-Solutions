// https://leetcode.com/problems/find-substring-with-given-hash-value

class Solution {
public:
    int md;
    long long po(long long a,long long b){
        if(b==0) return 1;
        if(a==0) return 0;
        long long x=1;
        while(b>0){
            if(b&1)x=(x*a)%md;
            b>>=1;
            a=(a*a)%md;
        }
        return x%md;
    }
    long long hash(string s,int p){
        long long v=0;
        for(int i=0;i<s.size();i++){
            v=(v%md+(((s[i]-'a'+1)%md)*po(p,i))%md)%md;
        }
        return v;
    }
    string subStrHash(string s, int power, int modulo, int k, int hashValue) {
        md=modulo;
        while(s.size()>=k){
            string t=s.substr(0,k);
            int h=hash(t,power)%md;
            if(h==hashValue) return t;
            s.erase(s.begin());
        }
        return "";
    }
};