class Solution {
public:
    int minCharacters(string a, string b) {
        vector<int>f1(26),f2(26);
        for(auto&i:a)f1[i-'a']++;
        for(auto&i:b)f2[i-'a']++;
        int res=INT_MAX,na=a.size(),nb=b.size();
        for(int i=0;i<26;i++){
            res=min(res,na+nb-f1[i]-f2[i]);
            if(i>0){
                f1[i]+=f1[i-1];
                f2[i]+=f2[i-1];
                res=min(res,na-f1[i-1]+f2[i-1]);
                res=min(res,nb-f2[i-1]+f1[i-1]);
            }
        }
        return res;
    }
};