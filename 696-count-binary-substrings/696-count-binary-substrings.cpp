class Solution {
public:
    int countBinarySubstrings(string s) {
        vector<int>cn;
        int c=1,ans=0,pvc=0;
        for(int i=1;i<size(s);++i){
            if(s[i]==s[i-1])++c;
            else{
               ans+=min(pvc,c);
                pvc=c;
                c=1;
            }
            
        }
        ans+=min(pvc,c);
        return ans;        
    }
};