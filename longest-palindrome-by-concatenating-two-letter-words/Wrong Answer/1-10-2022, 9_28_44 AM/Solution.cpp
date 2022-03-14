// https://leetcode.com/problems/longest-palindrome-by-concatenating-two-letter-words

class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int sl=0,ans=0,mx=0;
        unordered_map<string,int>mps;
        unordered_map<string,int>mp;
        for(auto& i:words){
            if(i[0]==i[1])mps[i]++;
            else mp[i]++;
        }
        for(auto [k,v]:mp){                          
            string t;
            t+=k[1];
            t+=k[0];
            if(mp.count(t)){
                ans+=(min(v,mp[t])*4);
                mp.erase(t);
            }            
        }
        for(auto [k,v]:mps){
            if(v%2) mx=max(mx,v);
            else {
                ans+=2*v;
                mps[k]=0;
            }
        }
        bool f=0;
        // cout<<mx<<" ";
        if(mx==1)ans+=2;
        else{            
            for(auto [k,v]:mps){
                if(!f && v==mx){
                    ans+=2*v;
                    f=1;
                }
                else ans+=(2*(v-1));
            }
        }
        // cout<<ans<<sl<<" ";
        return ans;
    }
};