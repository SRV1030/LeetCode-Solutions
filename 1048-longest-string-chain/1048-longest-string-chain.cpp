class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string& first, const string& second) {
            return first.size() < second.size();
	    });
        unordered_map<string,int>mp;
        int mx=1;
        for(auto&w:words){
            int lg=1;
            for(int i=0;i<w.size();i++){
                string t=w.substr(0,i)+w.substr(i+1);
                if(mp.count(t))lg=max(lg,mp[t]+1);
            }
            mp[w]=lg;
            mx=max(lg,mx);
        }
        return mx;
    }
};