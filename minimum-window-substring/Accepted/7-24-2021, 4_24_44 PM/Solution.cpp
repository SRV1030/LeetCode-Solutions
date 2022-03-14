// https://leetcode.com/problems/minimum-window-substring

class Solution {
public:
    string minWindow(string s, string t) {
        int ns=s.size(),nt=t.size();
        if(nt>ns || nt==0) return "";
        vector<int> fs(128,0);
        vector<int> ft(128,0);
        for(auto& i:t)ft[i]++;
        int si=-1,start=0,mx=INT_MAX,c=0;
        for(int i=0;i<ns;i++){
            fs[s[i]]++;
            if(ft[s[i]]!=0 && fs[s[i]] <= ft[s[i]]) c++;
            if(c==nt){
                while(ft[s[start]]==0 || fs[s[start]] > ft[s[start]]) {                    
                    fs[s[start]]--;
                    start++;
                }
                if(i-start+1<mx){
                    mx=i-start+1;
                    si=start;
                }
            }
        }
        return si==-1?"":s.substr(si,mx);    
    }
};