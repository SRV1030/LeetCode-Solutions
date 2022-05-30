class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        vector<int>f1(26),f2(26);
        int mx=INT_MAX;
        for(auto&i:s)f1[i-'a']++;
        for(auto&i:target)f2[i-'a']++;
        for(int i=0;i<26;i++){
            if(!f2[i])continue;
            if(f1[i]<f2[i]) return 0;
            mx=min(mx,f1[i]/f2[i]);            
        }
        return mx==INT_MAX?0:mx;
    }
};