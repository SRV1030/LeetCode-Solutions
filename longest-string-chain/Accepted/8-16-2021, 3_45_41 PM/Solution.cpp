// https://leetcode.com/problems/longest-string-chain

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        map<string,int>mp;
        int mx=1;
        sort(words.begin(),words.end(),[](string a,string b){return a.size()<b.size();});
        for(auto &i:words){
            int pre=1;
            if(i.length()==1){
                mp[i]=pre;
                continue;
            }
            string s=i;
            for(int j=0;j<s.length();j++){
                string temp;
                if(j==0) temp=s.substr(1);
                else if(j==s.length()-1) temp=s.substr(0,s.length()-1);
                else temp=s.substr(0,j)+s.substr(j+1);
                if(mp.count(temp)) pre=max(pre,1+mp[temp]);
            }
            mp[i]=pre;
            mx=max(mx,pre);
        }
        return mx;
    }
};