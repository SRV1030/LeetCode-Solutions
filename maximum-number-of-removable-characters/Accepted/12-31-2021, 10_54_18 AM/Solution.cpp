// https://leetcode.com/problems/maximum-number-of-removable-characters

class Solution {
public:
    vector<int>rem;
    bool isSub(string& s , string& p){
        int i = 0  ; int j = 0;
        while (i<p.length()){
            if (j==s.length()) return false;
            if (p[i]==s[j]){i++ ; j++;}
            else
                j++;
        }
        return true;
    }
    bool canRem(int ind,string s,string p){
        for(int i=0;i<ind;i++)s[rem[i]]='@';
        return isSub(s,p);
    }
    int maximumRemovals(string s, string p, vector<int>& removable) {
        rem=removable;
        int l=0,h=rem.size();
        while(l<h){
            int m=(l+h+1)/2;
            if(canRem(m,s,p)) l=m;
            else h=m-1;
        }
        return l;
    }
};