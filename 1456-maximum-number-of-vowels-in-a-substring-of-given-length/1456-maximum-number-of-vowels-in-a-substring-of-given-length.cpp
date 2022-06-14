class Solution {
public:
    bool isVowel(char a){
        return a=='a' || a=='e'|| a=='i' || a=='o' || a=='u';
    }
    int maxVowels(string s, int k) {
        int v=0,mx=0;
        for(int i=0;i<k;++i)if(isVowel(s[i]))++v;
        mx=v;
        for(int i=k;i<size(s);++i){
            if(isVowel(s[i-k]))--v;
            if(isVowel(s[i]))++v;
            mx=max(mx,v);
        }
        return mx;
    }
};