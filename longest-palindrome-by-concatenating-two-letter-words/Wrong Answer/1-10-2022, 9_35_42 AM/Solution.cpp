// https://leetcode.com/problems/longest-palindrome-by-concatenating-two-letter-words

class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int sl=0,ans=0,mx=0;
        map<string,int>mps;
        map<string,int>mp;
        for(auto& i:words){
            if(i[0]==i[1])mps[i]++;
            else mp[i]++;
        }
        for(auto&[k,v]:mp){                          
            string s;
            s+=k[1];
            s+=k[0];
            if(mp.count(s)){
                ans+=(min(v,mp[s])*4);
                mp.erase(s);
                mp.erase(k);
            }            
        }
        for(auto [k,v]:mps){
            if(v%2) mx=max(mx,v);
            else {
                ans+=2*v;
                mps.erase(k);
            }
        }
        bool f=0;
        for(auto [k,v]:mps){
            if(!f && v==mx){
                ans+=2*v;
                f=1;
            }
            else if(v>0)ans+=(2*(v-1));
        }
        return ans;
    }
};