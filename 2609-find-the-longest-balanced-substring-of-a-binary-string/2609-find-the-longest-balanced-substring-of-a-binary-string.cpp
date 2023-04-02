class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        int mx=0,cz=0;
        for(int i=0;i<size(s);++i){
            if(s[i]=='0')++cz;
            else{
                if(cz!=0){
                    int co=0;
                    while(s[i]=='1' && i<size(s)){
                        ++co;
                        ++i;
                    }
                    mx=max(min(co,cz)*2,mx);
                    --i;
                    cz=0;
                }
            }            
        }
        return mx;
    }
};