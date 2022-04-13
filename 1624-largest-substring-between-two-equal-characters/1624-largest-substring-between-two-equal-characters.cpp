class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int v[26]={},ans=-1;
        for(int i=0;i<s.size();i++){
            if(!v[s[i]-'a'])v[s[i]-'a']=i+1;
            ans=max(ans,i-v[s[i]-'a']);
        }
        return ans;
    }
};