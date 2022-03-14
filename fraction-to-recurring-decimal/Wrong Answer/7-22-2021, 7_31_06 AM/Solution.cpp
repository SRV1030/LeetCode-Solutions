// https://leetcode.com/problems/fraction-to-recurring-decimal

class Solution {
public:
    string fractionToDecimal(int n, int d) {
        if(n==0) return "0";
        string ans="";
        if(n<0 ^ d<0){
            ans.push_back('-');
            n=abs(n);
            d=abs(d);
        }        
        unsigned long long q=n/d;
        unsigned long long r=n%d;
        ans+=to_string(q);
        if(r==0) return ans;
        else{
            ans+='.';
            unordered_map<unsigned long long,int>mp;
            while(r!=0){
                if(mp.count(r)){                    
                    ans+=')';
                    ans.insert(mp[r],"(");
                    return ans;
                }else{
                    mp[r]=ans.length();
                    r*=10;
                    q=r/d;
                    r=r%d;
                    ans+=to_string(q);
                }
            }
        }
        return ans;
    }
};