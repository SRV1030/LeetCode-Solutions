// https://leetcode.com/problems/construct-string-with-repeat-limit

class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int>fr(26);
        for(auto&i:s)fr[i-'a']++;
        string ans;
        while(true){
            int i=25;
            bool onlyOne=false;
            for(;i>=0;i--){
                if(ans.size() && ans.back()-'a'==i && fr[i]){
                    onlyOne=true;
                    continue;
                }
                if(fr[i]) break;
            }
            if(i==-1) break;
            int cnt=onlyOne?1:min(repeatLimit,fr[i]);
            fr[i]-=cnt;
            while(cnt--) ans+=(i+'a');
        }
        return ans;
    }
};