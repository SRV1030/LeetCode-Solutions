class Solution {
public:
    string sortString(string s) {
        vector<int>f(26);
        for(auto&i:s)++f[i-'a'];
        string ans;
        for(int i=0;;++i){
            string t;
            bool entry=0;
            for(int j=0;j<26;++j)
                if(f[j]){
                    t+=(j+'a');
                    --f[j];
                    entry=1;
                }
            if(!entry) break;
            if(i%2)reverse(begin(t),end(t));
            ans+=t;
        }
        return ans;
    }
};