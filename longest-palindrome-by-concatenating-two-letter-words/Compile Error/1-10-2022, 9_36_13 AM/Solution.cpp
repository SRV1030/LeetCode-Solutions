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
        for(auto i:mp){                          
            string s=i.first;
            reverse(s.begin(),s.end());
            if(mp.count(s)){
                ans+=(min(v,mp[s])*4);
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
        cout<<mx<<" ";
                  
        for(auto [k,v]:mps){
            if(!f && v==mx){
                ans+=2*v;
                f=1;
            }
            else ans+=(2*(v-1));
        }
      
        // cout<<ans<<sl<<" ";
        return ans;
    }
};